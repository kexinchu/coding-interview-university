# 详细函数List可参考：
    [菜鸟教程](https://www.runoob.com/mysql/mysql-functions.html)

### IFNULL(expression, alt_value) 函数
- IFNULL() 函数用于判断第一个表达式是否为 NULL，如果为 NULL 则返回第二个参数的值，如果不为 NULL 则返回第一个参数的值

```
# LeetCode 1251, 平均售价

# 注意，有可能有货物没卖出去，但是有售价区间，此时应当返回0 ifnull 函数
# ifnull(a, 0) 函数 当入参a有值，返回指定的值；反之，当a 是null时候，返回指定的值 0 
SELECT
    p.product_id, ROUND(IFNULL(SUM(p.price * us.units) / SUM(us.units), 0), 2) as average_price
FROM 
    Prices AS p
LEFT JOIN
    UnitsSold AS us
ON
    p.product_id = us.product_id
WHERE 
    us.purchase_date BETWEEN p.start_date AND p.end_date
    OR us.product_id is null
GROUP BY
    p.product_id
```

### ROUND 保留小数点后位数
### SUM 求和
### AVG 求平均值
### COUNT 计数
- 用于计算某种情况出现的概率
```
# LeetCode 1211, 查询结果的质量和占比

SELECT
    query_name,
    ROUND(AVG(rating / position), 2) AS quality,
    ROUND(SUM(IF(rating < 3, 1, 0)) * 100 / COUNT(*), 2) as poor_query_percentage
FROM
    Queries
WHERE
    query_name IS NOT NULL 
    AND result IS NOT NULL
GROUP BY
    query_name
```


## 针对日期的函数
### DATE_SUB / DATE_ADD 实现日期的加减
```
# LeetCode 1141. 查询近30天的活跃用户数

SELECT
    activity_date AS day,
    COUNT(DISTINCT user_id) as active_users
FROM
    Activity
WHERE
    activity_date BETWEEN DATE_SUB('2019-07-27', INTERVAL 29 day) AND '2019-07-27'
GROUP BY
    activity_date
ORDER BY
    activity_date
```
