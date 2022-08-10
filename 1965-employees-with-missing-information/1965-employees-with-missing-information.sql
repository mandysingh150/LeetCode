# Write your MySQL query statement below
# select employee_id
# from (
#     select *
#     from employee as e
#     outer join
#     salaries as s
# ) as t
# where t.name is null or t.salary is null;
select t.employee_id
from (
    select * from employees e left join salaries s using(employee_id)
    union
    select * from employees e right join salaries s using(employee_id)
) as t
where t.name is null or t.salary is null
order by t.employee_id;