# Write your MySQL query statement below
select sell_date, COUNT(distinct product) AS num_sold, GROUP_CONCAT(distinct product ORDER BY product ASC SEPARATOR ',') AS products FROM Activities GROUP BY sell_date
