1select c.visited_on,
2(select sum(amount)
3  from customer
4  where visited_on between date_sub(c.visited_on, interval 6 day)
5  and c.visited_on) as amount,
6
7round((select sum(amount)/7
8from customer
9where visited_on between date_sub(c.visited_on, interval 6 day)
10and c.visited_on),2) as average_amount
11
12from customer c
13WHERE c.visited_on >= (
14SELECT DATE_ADD(MIN(visited_on), INTERVAL 6 DAY)
15FROM Customer
16)
17group by c.visited_on
18
19order by c.visited_on asc;