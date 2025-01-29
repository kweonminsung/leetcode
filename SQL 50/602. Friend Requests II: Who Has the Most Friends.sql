# Write your MySQL query statement below
SELECT id, num
FROM (
    SELECT id, COUNT(*) AS num, MAX(COUNT(*)) OVER() AS max_num
    FROM (
        SELECT requester_id AS id, accepter_id AS friend_id
        FROM RequestAccepted
        UNION ALL
        SELECT accepter_id AS id, requester_id AS friend_id
        FROM RequestAccepted
    ) AS E
    GROUP BY id
) AS F
WHERE num = max_num