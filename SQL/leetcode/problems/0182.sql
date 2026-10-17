select distinct
  p1.email as email
from
  person as p1
  join person as p2 on p2.email = p1.email
where
  p2.id > p1.id;
