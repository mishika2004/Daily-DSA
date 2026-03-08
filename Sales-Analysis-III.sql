1# Write your MySQL query statement below
2select p.product_id, p.product_name
3from product p 
4join sales s
5on p.product_id = s.product_id
6GROUP BY p.product_id, p.product_name
7HAVING MIN(s.sale_date) >= '2019-01-01'
8AND MAX(s.sale_date) <= '2019-03-31';