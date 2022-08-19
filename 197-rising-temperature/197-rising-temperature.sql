# Write your MySQL query statement below
SELECT w1.id AS 'Id'
FROM weather w1, weather w2
WHERE DATEDIFF(w1.recordDate, w2.recordDate) = 1 AND w1.Temperature > w2.Temperature;