### 事务的隔离级别
- 四种隔离级别： 
  - 读未提交，事务能够读取其他事务尚未提交的更改。可能会发生脏读（读取到未提交的数据）
  - 读已提交，事务只能读取其他事务已提交的更改。避免了脏读，但还是会有不可重复读 + 幻读的问题
  - 可重复读，在同一个事务中，多次读取相同的数据行时，结果总是相同。避免了不可重复读；针对幻读，通过MVCC解决  （MySQL默认的隔离界别）
  - 串行化(Serializable)， 最严格的隔离等级，强制事务串行执行，防止所有并发问题，-> 性能差
- 可重复读如何解决幻读问题
  - 幻读指的一个事务在两次执行相同的查询时，第二次查询时看到其他事务插入的新行
  - MySQL
- MVCC - Multi-Version Concurrency Control
  - MVCC 允许事务在数据库中保存多个数据版本，通过记录不同时间点的数据快照来解决幻读问题
  - 即：每个事务在启动时，创建一个读快照，后续事务内的查询都基于此快照
  - 间隙锁（Next-Key Lock）: 在可重复读隔离级别下，MySQL 会对查询条件匹配的行加锁，同时对这些行之间的“间隙”加上锁，防止其他事务在这些间隙中插入新的行。这防止了幻读的发生。例如，如果事务 A 锁定了值为 10 的行，并加了一个间隙锁，那么事务 B 在这个范围内（如插入值为 11 的行）会被阻塞。


### 随着MySQL中数据量的增加，如何提高效率
- 使用索引
    - 提升查询性能的最有效手段之一，可以极大减少数据库扫描的数据量，从而加速
        - 普通索引
        - 唯一索引，与普通索引类似，但是索引值必须为1，允许有空值  (ALTER TABLE `table_name` ADD UNIQUE(`column`))
        - 主键索引, 一种特殊的唯一索引，不允许有空值  (ALTER TABLE `table_name` ADD PRIMARY KEY(`column`))
        - 联合索引，ALTER TABLE `table_name` ADD INDEX index_name ( `column1`, `column2`, `column3` ) 
    - 优化方法：
        - 为频繁查询的列创建索引，如WHERE, JOIN, ORDER BY, GROUP BY中常用的列
        - 如果查询条件设计多个列，可以创建多个列的符合索引
            ```sql
            CREATE INDEX idx_user_name_email ON users (name, email);
            ```
    - 索引类型:
        - B+树 索引适用于范围查询，更广泛使用
        - hash 索引适用于精确查找
- 优化查询语句
    - 减少不必要的数据扫描和处理
    - 避免 select *
    - 避免使用cross join，尽量选择合适inner join 或者 left join
        ```sql
        select u.name, o.amount
        from users u
        inner join orders o on u.id = o.user_id;
        ```
    - 避免使用 or，多个or条件时，可以考虑用 in 提高性能
        ```sql
        select * from users where status in (1, 2);
        ```
    - 使用分页查询时，避免使用大偏移量
        ```sql
        select * from users where id > last_id order by id limit 10;
        ```
- 增加Redis缓存hot数据

- 分区表 (PARTITION)
    - 分区表是一种将表按指定列划分为多个部分的技术，分区后的表可以在查询时只扫描某个或某些分区，从而减少扫描的数据量。
    - 一般按照hash分区 
    - 查询的时候需要带上分区键
    ```sql
    CREATE TABLE orders (
        order_id INT,
        order_date DATE,
        customer_id INT,
        amount DECIMAL(10, 2)
    )
    PARTITION BY RANGE (YEAR(order_date)) (
        PARTITION p2019 VALUES LESS THAN (2020),
        PARTITION p2020 VALUES LESS THAN (2021),
        PARTITION p2021 VALUES LESS THAN (2022),
        PARTITION p2022 VALUES LESS THAN (2023)
    );

    SELECT * FROM orders WHERE order_date BETWEEN '2020-01-01' AND '2020-12-31'; 指定分区键
    ```
- 优化表结构
    - 选择合适的数据类型 (最小，最合适的类型)
    - 避免使用过大的列： 比如长的字符串类VARCHAR(255) 或者TEXT， 除非确实需要存储大数据

- 使用连接池
    - 高并发场景下，频繁创建和断开与数据库的连接会导致性能瓶颈；使用数据库连接池
    - 配置合理的连接池大小
- 分库分表
    - 当单个表的数据量过大时，缩小单个表的规模
    - 水平分表：将大表按照某个键拆分成多个子表，比如用户表按照用户ID来切分车工多个表
    - 垂直分表： 将表的不同列拆分成多个表


### MySQL中那些场景会用到联合索引
- where 条件有多个列
    ```sql
    SELECT * FROM users WHERE last_name = "Smith" AND first_name = "John";

    CREATE INDEX idx_name ON users (last_name, first_name);
    ```
- order by 或者 group by设计多个列
    ```sql
    SELECT * FROM orders WHERE customer_id = 134 ORDER BY order_date DESC;

    CREATE INDEX idx_customer_order ON orders (customer_id, order_date);
    ```
- join操作，尤其是设计多个列时, 对表分别创建联合索引
    ```sql
    SELECT u.name, o.amount FROM users u
    JOIN orders o ON u.id = o.user_id
    WHERE u.age = 30 AND o.status = 'shipped';
    ```

### MySQL的索引引擎
- InnoDB， 基于B+树实现
- 行级锁 vs 表级锁
    - InnoDB 存储引擎支持 行级锁（Row-level locking），也支持表级锁（Table-level locking）
    - InnoDB 默认使用锁粒度更小的 行级锁
        - 只lock具体数据行，允许多个事务并发的对不同的行进行操作，而不会相互阻塞
        - 优势是 支持高并发
    - 行级锁是基于索引实现的，如果一条 SQL 语句没有用到索引，InnoDB 存储引擎可能会退化为表级锁
        ```sql
        SELECT * FROM orders WHERE order_id = 123 FOR UPDATE;   // 行级锁

        SELECT * FROM orders WHERE customer_name = 'John' FOR UPDATE;  // 表级锁
        ```

### mysql为什么使用B+树，而不是红黑树
- 磁盘访问效率高：B+树是多路平衡树，且每个节点可以存储多个键值对（存储空间利用率高），可以减少树的高度，降低读取时访问的节点次数，而红黑树是二叉平衡树。
- 顺序访问效率高： B+树所有数据都存储在叶子节点，非叶子节点仅存储索引； B+树的叶子节点通过指针串联在一起，可以方便的进行范围查询和顺序查询，不像红黑树需要遍历算法
- 适合范围查询
- 稳定性和维护成本低
    - B+树的高度低
    - B+树平衡性好，在插入/删除时仅调整局部树结构，适合大规模数据库
- B树的缺点： 
    - 1，非叶子节点也存储数据，不方便进行范围查询和顺序查询
    - 2，B树的每个节点存储索引和数据，单个节点能存储的内容较少，因此树的高度相对较高
    - 3，B树数据存储在非叶子节点和叶子节点中，数据的分布不一致，可能导致访问路径不同，查询时性能波动较大。

### 有一个表，id字段是唯一的，name字段可以重复。写一个SQL语句，查询出所有的name重复的记录。
```sql
select * from Table_ group by name having count(DISTINCT id) > 1
```

### 分库分表需要考虑分布式事务，全局唯一ID的生成等问题
- 分布式事务
    - 单个数据库的事务可以通过数据库引擎内部的 ACID 机制（原子性、一致性、隔离性、持久性）来保证
    - TCC模式： Try - Confirm - Cancel
        - Try：尝试执行所有业务操作，预留资源。
        - Confirm：所有操作成功后确认提交事务，最终执行。
        - Cancel：如果某个操作失败，回滚之前的操作。

- 全局唯一ID生成
    - UUID 全局唯一ID
    - 数据库自增ID的方式： 给每个分库分配不同的ID段
    - 使用Redis的INCR或者INCRBY命令来实现全局自增ID，Redis是单线程 + 原子操作

- 分片路由算法
    - 分片路由规则可以基于某个字段（如用户 ID、订单 ID）进行哈希分片、取模等操作

### Golang 读写 MySQL


