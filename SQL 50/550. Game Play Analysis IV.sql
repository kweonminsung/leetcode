# Write your MySQL query statement below
SELECT ROUND(COUNT(IF(ok = 1, 1, NULL)) / COUNT(*), 2) AS fraction
FROM (
    SELECT A.player_id, MAX(IF(B.player_id IS NOT NULL, 1, 0)) AS ok
    FROM (
        SELECT player_id, MIN(event_date) AS event_date
        FROM Activity
        GROUP BY player_id
    ) AS A
    LEFT JOIN Activity AS B
    ON date_add(A.event_date, interval 1 day) = B.event_date
    AND A.player_id = B.player_id
    GROUP BY A.player_id
) AS C