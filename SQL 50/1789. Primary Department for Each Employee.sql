# Write your MySQL query statement below
SELECT employee_id, department_id
FROM Employee
WHERE primary_flag = 'Y'
OR employee_id IN (
    SELECT employee_id
    FROM (
        SELECT employee_id, COUNT(*) AS cnt
        FROM Employee
        GROUP BY employee_id
    ) AS A
    WHERE cnt = 1
)