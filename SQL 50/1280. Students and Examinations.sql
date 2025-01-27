# Write your MySQL query statement below
SELECT A.student_id, A.student_name, A.subject_name, COUNT(IF(flag = 1, flag, NULL)) AS attended_exams
FROM (
    SELECT *
    FROM Students
    CROSS JOIN Subjects
) AS A
LEFT JOIN (
    SELECT *, 1 AS flag
    FROM Examinations
) AS B
ON A.student_id = B.student_id AND A.subject_name = B.subject_name
GROUP BY A.student_id, A.subject_name
ORDER BY A.student_id, A.subject_name