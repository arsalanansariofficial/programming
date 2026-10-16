select
  employee.name as employee
from
  employee
  join employee as manager on manager.id = employee.managerid
where
  employee.salary > manager.salary;
