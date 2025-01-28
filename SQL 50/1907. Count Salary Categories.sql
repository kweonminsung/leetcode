# Write your MySQL query statement below
WITH Cat AS (
    SELECT 'Low Salary' AS category
    UNION ALL
    SELECT 'Average Salary' AS category
    UNION ALL
    SELECT 'High Salary' AS category
)
SELECT Cat.category, COUNT(IF(income IS NOT NULL, income, NULL)) AS accounts_count
FROM Cat
LEFT JOIN (
    SELECT *,
        CASE
            WHEN income < 20000 THEN 'Low Salary'
            WHEN income <= 50000 THEN 'Average Salary'
            ELSE 'High Salary'
        END AS category
    FROM Accounts
) AS A
ON Cat.category = A.category
GROUP BY A.category