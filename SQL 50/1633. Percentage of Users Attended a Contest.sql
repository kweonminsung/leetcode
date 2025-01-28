# Write your MySQL query statement below
SELECT contest_id, ROUND(100 * COUNT(Users.user_id) / (SELECT COUNT(*) FROM Users), 2) AS percentage
FROM Register
JOIN Users
ON Register.user_id = Users.user_id
GROUP BY contest_id
ORDER BY percentage DESC, contest_id ASC