# Write your MySQL query statement below
SELECT activity_date AS day, COUNT(*) AS active_users
FROM (
    SELECT activity_date, user_id
    FROM Activity
    WHERE '2019-06-28' <= activity_date AND '2019-7-27' >= activity_date
    GROUP BY user_id, activity_date
) AS A
GROUP BY activity_date