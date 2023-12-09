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