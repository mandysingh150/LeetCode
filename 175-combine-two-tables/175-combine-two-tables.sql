# Write your MySQL query statement below
select firstname, lastname, city, state
from address as a right join person as p
on a.personId=p.personId