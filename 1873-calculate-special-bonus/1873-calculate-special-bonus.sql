# Write your MySQL query statement below
select employee_id, salary "bonus"
from employees
where employee_id%2 <> 0 and name not like "M%"
union
select employee_id, 0 "bonus"
from employees
where not (employee_id%2 <> 0 and name not like "M%")
order by employee_id;