# Write your MySQL query statement below
WITH new_ins AS (
    SELECT pid, tiv_2015, tiv_2016, CONCAT(lat, ',', lon) AS loc
    FROM Insurance
)
SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM new_ins
WHERE tiv_2015 NOT IN (
    SELECT tiv_2015
    FROM (
        SELECT tiv_2015, COUNT(*) AS tiv_2015_cnt
        FROM new_ins
        GROUP BY tiv_2015
    ) AS A
    WHERE tiv_2015_cnt = 1
)
AND loc IN (
    SELECT loc
    FROM (
        SELECT loc, COUNT(*) AS loc_cnt
        FROM new_ins
        GROUP BY loc
    ) AS B
    WHERE loc_cnt = 1
)