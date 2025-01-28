# Write your MySQL query statement below
SELECT customer_id
FROM (
    SELECT MIN(IF(C.customer_id IS NOT NULL, true, false)) AS all_buy, A.customer_id
    FROM (SELECT DISTINCT customer_id FROM Customer) AS A
    JOIN Product
    LEFT JOIN Customer AS C
    ON A.customer_id = C.customer_id AND Product.product_key = C.product_key
    GROUP BY A.customer_id
) AS D
WHERE all_buy = 1