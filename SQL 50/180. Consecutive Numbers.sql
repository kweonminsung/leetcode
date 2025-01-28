# Write your MySQL query statement below
SELECT DISTINCT A.num AS ConsecutiveNums
FROM Logs AS A
LEFT JOIN Logs AS B
ON A.id + 1 = B.id
LEFT JOIN Logs AS C
ON B.id + 1 = C.id
WHERE A.num = B.num AND B.num = C.num 
AND B.id IS NOT NULL AND C.id IS NOT NULL