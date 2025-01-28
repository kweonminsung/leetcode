# Write your MySQL query statement below
SELECT class
FROM (
    SELECT COUNT(student) AS students, class
    FROM Courses
    GROUP BY class
) AS A
WHERE students >= 5