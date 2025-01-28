# Write your MySQL query statement below
SELECT *
FROM (
    SELECT name AS results
    FROM (
        SELECT MAX(cnt) OVER() AS max_cnt, cnt, user_id
        FROM (
            SELECT user_id, COUNT(*) AS cnt
            FROM MovieRating
            GROUP BY user_id
        ) AS A
    ) AS B
    JOIN Users
    ON Users.user_id = B.user_id
    WHERE max_cnt = cnt
    ORDER BY name
    LIMIT 1
) AS E

UNION ALL

SELECT *
FROM (
    SELECT title AS results
    FROM (
        SELECT MAX(rate) OVER() AS max_rate, rate, movie_id
        FROM (
            SELECT movie_id, AVG(rating) as rate
            FROM MovieRating
            WHERE YEAR(created_at) = 2020 AND MONTH(created_at) = 2
            GROUP BY movie_id
        ) AS C
    ) AS D
    JOIN Movies
    ON Movies.movie_id = D.movie_id
    WHERE max_rate = rate
    ORDER BY title
    LIMIT 1
) AS F