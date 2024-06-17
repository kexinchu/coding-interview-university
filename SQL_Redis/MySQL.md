## 数据库操作
- 连接MYSQL
  mysql -u your_username -p
- 创建/删除/选择
    - 创建数据库
    ```
    # IF NOT EXISTS 避免当数据库已经存在报错
    # CHARACTER SET 指定字符集
    # COLLATE 排序类型，会影响SQL中字符类型的列的顺序 
    CREATE DATABASE [IF NOT EXISTS] database_name
      [CHARACTER SET charset_name]
      [COLLATE collation_name];
    # eg
    CREATE DATABASE mydatabase
      CHARACTER SET utf8mb4
      COLLATE utf8mb4_general_ci;
    ```
    - 删除数据库
    ```
    # IF EXISTS 确定存在再删除
    DROP DATABASE IF EXISTS RUNOOB;
    ```
    - 选择数据库
    ```
    USE database_name;
    ```

## 数据类型
#### 数值类型
|类型|大小|范围（有符号）|范围（无符号）|用途|
|:--|:--|:--|:--|:--|
|TINYINT|1 Bytes|(-128，127)|(0，255)|小整数值|
|SMALLINT|2 Bytes|(-32 768，32 767)|(0，65 535)|大整数值|
|MEDIUMINT|3 Bytes|(-8 388 608，8 388 607)|(0，16 777 215)|大整数值|
|INT或INTEGER|4 Bytes|(-2 147 483 648，2 147 483 647)|(0，4 294 967 295)|大整数值|
|BIGINT|8 Bytes|(-9,223,372,036,854,775,808，9 223 372 036 854 775 807)|(0，18 446 744 073 709 551 615)|极大整数值|
|FLOAT|4 Bytes|(-3.402 823 466 E+38，-1.175 494 351 E-38)，0，(1.175 494 351 E-38，3.402 823 466 351 E+38)|0，(1.175 494 351 E-38，3.402 823 466 E+38)|单精度    浮点数值|
|DOUBLE|8 Bytes|(-1.797 693 134 862 315 7 E+308，-2.225 073 858 507 201 4 E-308)，0，(2.225 073 858 507 201 4 E-308，1.797 693 134 862 315 7 E+308)|0，(2.225 073 858 507 201 4 E-308，1.797 693 134 862 315 7 E+308)|双精度    浮点数值|
|DECIMAL|对DECIMAL(M,D) ，如果M>D，为M+2否则为D+2|依赖于M和D的值|依赖于M和D的值|小数值|

#### 日期及时间类型
|类型|大小  (bytes)|范围|格式|用途|
|:--|:--|:--|:--|:--|
|DATE|3|1000-01-01/9999-12-31|YYYY-MM-DD|日期值|
|TIME|3|'-838:59:59'/'838:59:59'|HH:MM:SS|时间值或持续时间|
|YEAR|1|1901/2155|YYYY|年份值
|DATETIME|8|'1000-01-01 00:00:00' 到 '9999-12-31 23:59:59'|YYYY-MM-DD hh:mm:ss|混合日期和时间值|
|TIMESTAMP|4|'1970-01-01 00:00:01' UTC 到 '2038-01-19 03:14:07' UTC    结束时间是第 2147483647 秒，北京时间 2038-1-19 11:14:07，格林尼治时间 2038年1月19日 凌晨 03:14:07|YYYY-MM-DD hh:mm:ss|	混合日期和时间值，时间戳|

#### 字符串类型
- 2^8 = 256
- 2^16 = 65536
- 2^24 = 16777216
- 2^32 = 4294967296

|类型|大小|用途|
|:--|:--|:--|
|CHAR|0-255 bytes|定长字符串|
|VARCHAR|0-65535 bytes|变长字符串|
|TINYBLOB|0-255 bytes|不超过 255 个字符的二进制字符串|
|TINYTEXT|0-255 bytes|短文本字符串|
|BLOB|0-65535 bytes|二进制形式的长文本数据|
|TEXT|0-65535 bytes|长文本数据|
|MEDIUMBLOB|0-16777215 bytes|二进制形式的中等长度文本数据|
|MEDIUMTEXT|0-16777215 bytes|中等长度文本数据|
|LONGBLOB|0-4294967295 bytes|二进制形式的极大文本数据|
|LONGTEXT|0-4294967295 bytes|极大文本数据|

#### 枚举和集合类型
ENUM: 枚举类型，用于存储单一值，可以选择一个预定义的集合。
SET: 集合类型，用于存储多个值，可以选择多个预定义的集合。

## 表操作
  - 创建表 - 声明表中的每一列及其类型
    ```
    # 语法
    CREATE TABLE table_name (
        column1 datatype,
        column2 datatype,
        ...
    );

    # eg
    CREATE TABLE users (
        id INT AUTO_INCREMENT PRIMARY KEY,
        username VARCHAR(50) NOT NULL,
        email VARCHAR(100) NOT NULL,
        birthdate DATE,
        is_active BOOLEAN DEFAULT TRUE
    );
    ```
    - 特殊字符
        - CHARACTER SET 指定字符集
        - COLLATE  指定排序
        - AUTO_INCREMENT 定义列为自增的属性，一般用于主键，数值会自动加 1。
        - PRIMARY KEY 关键字用于定义列为主键。 您可以使用多列来定义主键，列间以逗号 , 分隔。
        - ENGINE 设置存储引擎
        - CHARSET 设置编码。

  - 删除表
    ```
    DROP TABLE table_name ;    # 直接删除表，不检查是否存在
    # OR
    DROP TABLE IF EXISTS table_name;
    ```

## 增/删/改/查
  - 插入数据: INSERT INTO

    ```
    # 语法
    INSERT INTO table_name (column1, column2, column3, ...)
    VALUES (value1, value2, value3, ...);

    # eg
    INSERT INTO users (username, email, birthdate, is_active)
    VALUES ('test', 'test@runoob.com', '1990-01-01', true);
    ```

  - 删除数据: DELETE

    ```
    DELETE FROM table_name
    WHERE 筛选条件
    ```

  - 修改数据: UPDATE
    需要更新多个值时，用逗号 , 隔开
    ```
    UPDATE table_name
    SET salary = 60000
    WHERE employee_id = 101;
    ```

  - 查找数据 SELECT

## UNION
  - UNION 操作符用于连接两个以上的 SELECT 语句的结果组合到一个结果集合，并去除重复的行。
      - UNION 操作符必须由两个或多个 SELECT 语句组成，每个 SELECT 语句的列数和对应位置的数据类型必须相同。
  - UNION ALL 不去除重复行

  ```
  SELECT product_name FROM products WHERE category = 'Electronics'
  UNION
  SELECT product_name FROM products WHERE category = 'Clothing'
  ORDER BY product_name;
  ```

## 连接(JOIN)
  - INNER JOIN（内连接,或等值连接）：获取两个表中字段匹配关系的记录。
  - LEFT JOIN（左连接）：获取左表所有记录，即使右表没有对应匹配的记录。
  - RIGHT JOIN（右连接）： 与 LEFT JOIN 相反，用于获取右表所有记录，即使左表没有对应匹配的记录。

## 排序 ORDER BY
  - 可以按照一个或多个列的值进行升序（ASC）或降序（DESC）排序

  ```
  SELECT column1, column2, ...
  FROM table_name
  ORDER BY column1 [ASC | DESC], column2 [ASC | DESC], ...;

  # eg
  SELECT product_name, price * discount_rate AS discounted_price
  FROM products
  ORDER BY discounted_price DESC;
  ```

## 分组 GROUP BY
  - GROUP BY 语句根据一个或多个列对结果集进行分组

  ```
  SELECT column1, aggregate_function(column2)
  FROM table_name
  WHERE condition
  GROUP BY column1;
  ```

## 正则表达式
  - LIKE 可以进行模糊匹配
      - 使用百分号 %字符来表示任意字符，类似于UNIX或正则表达式中的星号 *。没有 % ,LIKE语句跟 = 无区别
  - REGEXP 是用于进行正则表达式匹配的运算符
  - RLIKE 是 MySQL 中用于进行正则表达式匹配的运算符，与 REGEXP 是一样的，RLIKE 和 REGEXP 可以互换使用，没有区别。

## 事务

## 数据导入/导出