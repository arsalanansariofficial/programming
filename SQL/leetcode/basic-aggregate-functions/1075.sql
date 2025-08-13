select project.project_id as project_id,
  round(avg(employee.experience_years), 2) as average_years
from employee
  join project on project.empid = employee.empid
group by project.project_id;