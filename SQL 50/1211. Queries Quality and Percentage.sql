# Write your MySQL query statement below
SELECT query_name, ROUND(AVG(rating / position), 2) AS quality, ROUND(100 * COUNT(IF(rating < 3, rating, NULL)) / COUNT(rating), 2) AS poor_query_percentage
FROM Queries
GROUP BY query_name