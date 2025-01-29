# Write your MySQL query statement below
SELECT product_name, sum_unit AS unit
FROM (
    SELECT product_id, SUM(unit) AS sum_unit
    FROM Orders
    WHERE YEAR(order_date) = 2020 AND MONTH(order_date) = 2
    GROUP BY product_id
) AS A
JOIN Products
ON A.product_id = Products.product_id
WHERE sum_unit >= 100