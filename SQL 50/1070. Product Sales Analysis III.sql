# Write your MySQL query statement below
SELECT product_id, first_year, quantity, price
FROM (
    SELECT Sales.product_id, MIN(year) OVER(PARTITION BY Sales.product_id) AS first_year, quantity, price, year
    FROM Sales
    JOIN Product
    ON Sales.product_id = Product.product_id
) AS A
WHERE first_year = year