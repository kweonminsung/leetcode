# Write your MySQL query statement below
SELECT Department.name AS Department, Employee.name AS Employee, B.salary AS Salary
FROM (
    SELECT salary, departmentId, RANK() OVER(PARTITION BY departmentId ORDER BY salary DESC) AS ranking
    FROM (
        SELECT salary, departmentId
        FROM Employee
        GROUP BY salary, departmentId
    ) AS A
) AS B
JOIN Employee
ON B.salary = Employee.salary AND B.departmentId = Employee.departmentId
JOIN Department
ON B.departmentId = Department.id
WHERE ranking <= 3