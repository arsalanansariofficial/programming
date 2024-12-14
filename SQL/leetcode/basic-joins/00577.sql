select e.name
from employee as e
  left join bonus as b on b.empid = e.empid
where b.bonus < 1000
  or b.bonus is null;