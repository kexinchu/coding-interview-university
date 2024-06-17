

MySQL 使用三值逻辑 —— TRUE, FALSE 和 UNKNOWN。任何与 NULL 值进行的比较都会与第三种值 UNKNOWN 做比较。这个“任何值”包括 NULL 本身！这就是为什么 MySQL 提供 IS NULL 和 IS NOT NULL 两种操作来对 NULL 特殊判断。



## 实际做题记录
#### DISTINCT 关键字用于过滤重复元素
#### 排序: ORDER BY; 按照多个维度排序时用逗号隔开
```
# LeetCode 1148. 文章浏览I

SELECT 
    DISTINCT author_id AS id
FROM 
    Views
WHERE
    author_id = viewer_id
ORDER BY
    id

# LeetCode 1663. 各赛事的用户注册率

# 有人可能没有注册任何比赛
# LEFT JOIN Register 到 Users 会导致contest列出现null
SELECT 
    r.contest_id,
    ROUND(COUNT(r.user_id) / (SELECT COUNT(*) FROM Users) * 100, 2) AS percentage
FROM
    Users AS u
LEFT JOIN
    Register AS r
ON
    u.user_id = r.user_id
WHERE
    r.contest_id is not NULL
GROUP BY
    r.contest_id
ORDER BY
    percentage DESC,
    contest_id ASC
```

### 计算字符串长度： CHAR_LENGTH 和 LENGTH
- CHAR_LENGTH(str) 返回严格的字符串str长度
- LENGTHZ(str) 遇到特殊字符时，返回的长度可能>1; 
```
# LeetCode 1683. 无效推文

SELECT
    tweet_id
FROM
    Tweets
WHERE
    CHAR_LENGTH(content) > 15
```

#### JOIN 并表查询
- LEFT JOIN可以将两个表按照某一列的结果进行组合
```
# LeetCode 1378. 使用唯一标识码替换员工ID

SELECT
    EmployeeUNI.unique_id, Employees.name
FROM
    Employees
LEFT JOIN
    EmployeeUNI
ON
    Employees.id = EmployeeUNI.id
```

```
# LeetCode 1068. 产品销售分析I

SELECT
    Product.product_name, Sales.year, Sales.price
FROM
    Sales
LEFT JOIN
    Product
ON
    Sales.product_id = Product.product_id
```
- INNER JOIN (等值连接)只返回两个表中链接字段相等的行
    - 计算时间的函数 DATEDIFF(日期1，日期2)； 可以得到相差的天数
```
# LeetCode 197. 上升的温度

SELECT
    w1.id as Id
FROM
    Weather w1
INNER JOIN
    Weather w2
WHERE
    datediff(w1.recordDate, w2.recordDate) = 1 AND w1.temperature > w2.temperature
```

#### GROUP BY 分组聚合，一般当需要在统计时按照某个键聚合数据；使用GROUP BY限制聚合的结果
```
# LeetCode 1581. 进店却未能完成交易的客户
# 这一题中如果不使用GROUP BY customer_id; 输出的结果会是下面这样，因为聚合时没有区分不同顾客ID
# | customer_id | count_no_trans |
# | ----------- | -------------- |
# | 30          | 4              |

SELECT
    customer_id, COUNT(customer_id) as count_no_trans
FROM
    Visits
LEFT JOIN
    Transactions
ON
    Visits.visit_id = Transactions.visit_id
WHERE
    transaction_id is NULL
GROUP BY
    customer_id
```

#### AVG 计算均值 + ROUND保留位数
```
# LeetCode 1661. 每台机器的进程平均运行时间

SELECT
    A1.machine_id, 
    ROUND(avg(a2.timestamp - a1.timestamp), 3) as processing_time
FROM
    Activity A1
INNER JOIN
    Activity A2
ON
    A1.machine_id = A2.machine_id 
    AND A1.process_id = A2.process_id 
    AND A1.activity_type = "start" 
    AND A2.activity_type = "end"
GROUP BY
    machine_id
```