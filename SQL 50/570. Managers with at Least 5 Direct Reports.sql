# Write your MySQL query statement below
SELECT name
FROM (
    SELECT COUNT(*) AS reports, A.name
    FROM Employee AS A
    LEFT JOIN Employee AS B
    ON A.id = B.managerId
    GROUP BY A.id
) AS C
WHERE reports >= 5