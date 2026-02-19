1# Write your MySQL query statement below
2Select CASE 
3 WHEN id%2!=0 AND id= (select MAX(id) from Seat) then id
4 when id%2!=0 then id+1
5 else id-1
6 end as id , student
7 from seat
8 order by id;
9
10
11  