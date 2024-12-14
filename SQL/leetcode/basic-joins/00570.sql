select e1.name
from employee_man as e1
  join employee_man as e2 on e2.managerid = e1.id
group by e1.id,
  e1.name
having count(*) > 4;