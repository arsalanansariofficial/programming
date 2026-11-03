-- 1873. Calculate Special Bonus
-- https://leetcode.com/problems/calculate-special-bonus/description/
select
  employee_id,
  case
    when mod(employee_id, 2) = 0 then 0
    when lower(name) like 'm%' then 0
    when mod(employee_id, 2) != 0
    and lower(name) not like 'm%' then salary
  end as bonus
from
  employees
order by
  employee_id;
