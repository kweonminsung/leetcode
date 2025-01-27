# Write your MySQL query statement below
SELECT Prices.product_id, IF(SUM(units) IS NULL, 0.00, ROUND(SUM(price * units) / SUM(units), 2)) AS average_price
FROM Prices
LEFT JOIN UnitsSold
ON Prices.product_id = UnitsSold.product_id
AND Prices.start_date <= purchase_date AND Prices.end_date >= purchase_date
GROUP BY Prices.product_id