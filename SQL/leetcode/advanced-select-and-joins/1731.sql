select manager.employee_id as employee_id,
  manager.name as name,
  count(employee.reports_to) as reports_count,
  round(avg(employee.age)) as average_age
from employees as employee
  join employees as manager on manager.employee_id = employee.reports_to
group by manager.employee_id
order by manager.employee_id;