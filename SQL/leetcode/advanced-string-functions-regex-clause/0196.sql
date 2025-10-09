delete p1
from person as p1
  join person as p2 on p2.email = p1.email
  and p1.id > p2.id;