select department,
  employee,
  salary
from (
    select department.name as department,
      employee.name as employee,
      salary,
      dense_rank() over (
        partition by departmentid
        order by salary desc
      ) as position
    from employee
      join department on department.id = employee.departmentid
  ) as ranked
where position <= 3;