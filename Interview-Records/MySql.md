### MySQL



### 随着MySQL中数据量的增加，如何提高效率
- 使用索引
    - 提升查询性能的最有效手段之一，可以极大减少数据库扫描的数据量，从而加速
        - 普通索引
        - 唯一索引，与普通索引类似，但是索引值必须为1，允许有空值  (ALTER TABLE `table_name` ADD UNIQUE(`column`))
        - 主键索引, 一种特殊的唯一索引，不允许有空值  (ALTER TABLE `table_name` ADD PRIMARY KEY(`column`))
        - 组合索引，ALTER TABLE `table_name` ADD INDEX index_name ( `column1`, `column2`, `column3` ) 
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


### 分库分表需要考虑分布式事务，全局唯一ID的生成等问题


### Golang 读写 MySQL


