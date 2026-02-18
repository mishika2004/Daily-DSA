1# Write your MySQL query statement below
2select p.product_id,
3ROUND(
4    IFNULL(SUM(p.price*u.units)/SUM(u.units),0),2) as average_price
5from prices p 
6left join unitsSold u
7ON p.product_id = u.product_id
8AND u.purchase_date BETWEEN p.start_date AND p.end_date
9GROUP BY p.product_id;