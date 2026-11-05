select
  name as customers
from
  customers as c
  left join orders as o on o.customerid = c.id
where
  o.id is null;
