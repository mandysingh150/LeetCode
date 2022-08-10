# Write your MySQL query statement below
# select employee_id
# from (
#     select *
#     from employee as e
#     outer join
#     salaries as s
# ) as t
# where t.name is null or t.salary is null;
select employee_id
from employees
where employee_id not in (select employee_id from salaries)

union

select employee_id
from salaries
where employee_id not in (select employee_id from employees)

order by employee_id;