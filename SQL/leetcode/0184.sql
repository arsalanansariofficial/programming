select
  d.name as Department,
  e.name as Employee,
  e.salary as Salary
from
  employee as e
  join department as d on d.id = e.departmentId
where
  (e.departmentId, salary) in (
    select
      departmentId,
      max(salary)
    from
      employee
    group by
      departmentId
  );
