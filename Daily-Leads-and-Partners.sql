1# Write your MySQL query statement below
2select date_id, make_name,
3COUNT(distinct lead_id) as unique_leads,
4COUNT(distinct partner_id) as unique_partners
5From DailySales
6group by date_id, make_name
7order by date_id, make_name;