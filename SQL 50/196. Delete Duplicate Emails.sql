# Write your MySQL query statement below
DELETE
FROM Person
WHERE id NOT IN (
    SELECT MIN(id) AS id
    FROM Person
    GROUP BY email
)

-- DELETE p
-- FROM Person p, Person q
-- WHERE p.Id > q.Id
-- AND q.Email = p.Email