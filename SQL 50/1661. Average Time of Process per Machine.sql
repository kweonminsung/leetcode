# Write your MySQL query statement below
SELECT S.machine_id, ROUND(AVG(E.timestamp - S.timestamp), 3) AS processing_time
FROM Activity AS S
JOIN Activity AS E
ON S.process_id = E.process_id AND S.machine_id = E.machine_id AND E.activity_type = 'end'
WHERE S.activity_type = 'start'
GROUP BY machine_id;