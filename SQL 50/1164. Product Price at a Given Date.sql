# Write your MySQL query statement below
SELECT B.product_id, IFNULL(new_price, 10) AS price
FROM (
    SELECT DISTINCT product_id
    FROM Products
) AS B
LEFT JOIN (
    SELECT *
    FROM (
        SELECT *, MAX(change_date) OVER(PARTITION BY product_id) AS latest_date
        FROM Products
        WHERE change_date <= '2019-08-16'
    ) AS A
    WHERE latest_date = change_date
) AS C
ON B.product_id = C.product_id