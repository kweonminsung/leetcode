# Write your MySQL query statement below
-- SELECT sell_date, COUNT(*) AS num_sold, GROUP_CONCAT(product ORDER BY product ASC) AS products
-- FROM (
--     SELECT sell_date, product
--     FROM Activities
--     GROUP BY sell_date, product
-- ) AS A
-- GROUP BY sell_date
-- ORDER BY sell_date

SELECT sell_date, COUNT(DISTINCT product) AS num_sold, GROUP_CONCAT(DISTINCT product) AS products 
FROM activities 
GROUP BY sell_date;