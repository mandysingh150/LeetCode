# Write your MySQL query statement below
select firstname, lastname, city, state
from person as p
left join
address as a
on a.personId=p.personId