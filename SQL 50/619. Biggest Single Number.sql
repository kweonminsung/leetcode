# Write your MySQL query statement below
SELECT IFNULL(MAX(num), NULL) AS num
FROM (
    SELECT COUNT(*) AS cnt, num
    FROM MyNumbers
    GROUP BY num
) AS A
WHERE cnt = 1