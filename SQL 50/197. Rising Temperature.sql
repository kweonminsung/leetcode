# Write your MySQL query statement below
SELECT A.id AS Id
FROM Weather AS A
LEFT JOIN Weather AS B
ON date_sub(A.recordDate, interval 1 day) = B.recordDate
WHERE A.temperature > B.temperature;