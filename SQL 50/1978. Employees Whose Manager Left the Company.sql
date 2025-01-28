# Write your MySQL query statement below
SELECT A.employee_id
FROM Employees AS A
LEFT JOIN Employees AS B
ON A.manager_id = B.employee_id
WHERE A.manager_id IS NOT NULL AND B.name IS NULL AND A.salary < 30000
ORDER BY A.employee_id