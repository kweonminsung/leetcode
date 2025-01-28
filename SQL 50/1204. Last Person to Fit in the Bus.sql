# Write your MySQL query statement below
WITH RECURSIVE A AS (
    SELECT 1 AS n, weight AS total_weight
    FROM Queue
    WHERE turn = 1

    UNION ALL

    SELECT n + 1 AS n, (SELECT SUM(weight) FROM Queue WHERE turn <= n + 1) AS total_weight
    FROM A
    WHERE n <= (SELECT MAX(turn) FROM Queue)
)
SELECT person_name
FROM A
JOIN Queue
ON A.n = Queue.turn
WHERE total_weight <= 1000
ORDER BY turn DESC
LIMIT 1