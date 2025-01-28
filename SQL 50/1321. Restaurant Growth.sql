# Write your MySQL query statement below
SELECT A.visited_on, SUM(amount) AS amount, ROUND(SUM(amount) / 7, 2) AS average_amount
FROM (
    SELECT DISTINCT visited_on
    FROM Customer
    WHERE date_sub(visited_on, interval 6 day) IN (
        SELECT DISTINCT visited_on
        FROM Customer
    )
) AS A
LEFT JOIN Customer AS B
ON date_sub(A.visited_on, interval 6 day) <= B.visited_on AND B.visited_on <= A.visited_on
GROUP BY A.visited_on