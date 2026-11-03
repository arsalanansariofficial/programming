-- 1965. Employees With Missing Information
-- https://leetcode.com/problems/employees-with-missing-information/description/
select distinct
  employee_id
from
  (
    select
      s.employee_id as employee_id,
      e.name as name,
      s.salary as salary
    from
      salaries as s
      left join employees as e on e.employee_id = s.employee_id
    union all
    select
      e.employee_id as employee_id,
      e.name as name,
      s.salary as salary
    from
      employees as e
      left join salaries as s on s.employee_id = e.employee_id
  ) as employee_with_missing_information
where
  name is null
  or salary is null
order by
  employee_id;
