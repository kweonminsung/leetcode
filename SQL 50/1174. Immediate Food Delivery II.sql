# Write your MySQL query statement below
SELECT ROUND(100 * COUNT(IF(immediate = true, 1, NULL)) / COUNT(*), 2) AS immediate_percentage
FROM (
    SELECT *
    FROM (
        SELECT *, MIN(order_date) OVER(PARTITION BY customer_id) AS min_order_date, IF(order_date = customer_pref_delivery_date, true, false) AS immediate
        FROM Delivery
    ) AS B
    WHERE min_order_date = order_date
) AS A