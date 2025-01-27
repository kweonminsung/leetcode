# Write your MySQL query statement below
SELECT Signups.user_id, IF(COUNT(action) = 0, 0.00, ROUND(COUNT(IF(action = 'confirmed', action, NULL)) / COUNT(action), 2)) AS confirmation_rate
FROM Signups
LEFT JOIN Confirmations
ON Signups.user_id = Confirmations.user_id
GROUP BY Signups.user_id