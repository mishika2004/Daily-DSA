1# Write your MySQL query statement below
2select 
3    distinct product_id,
4    10 as price
5from 
6    products
7group by
8    product_id
9having
10    min(change_date) > "2019-08-16"
11
12union
13
14select 
15    product_id, 
16    new_price
17from 
18    Products 
19where 
20    (product_id, change_date) in(
21                                select 
22                                    product_id, 
23                                    max(change_date) as recent_date
24                                from 
25                                    Products
26                                where 
27                                    change_date <= "2019-08-16"
28                                group by 
29                                    product_id
30                                );