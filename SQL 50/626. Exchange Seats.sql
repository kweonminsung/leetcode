# Write your MySQL query statement below
SELECT id, student
FROM (
    SELECT id + 1 AS id, student
    FROM Seat
    WHERE MOD(id, 2) = 1 AND (id != (SELECT MAX(id) FROM Seat))
    UNION ALL
    SELECT id - 1 AS id, student
    FROM Seat
    WHERE MOD(id, 2) = 0
    UNION ALL
    SELECT IF(MOD((SELECT MAX(id) FROM Seat), 2) = 1, id, NULL) AS id, student
    FROM Seat
    WHERE id = (SELECT MAX(id) FROM Seat)
) AS A
WHERE id IS NOT NULL
ORDER BY id ASC