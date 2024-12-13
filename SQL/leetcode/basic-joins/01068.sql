select product_name,
  year,
  price
from product as p
  join sales as s on s.product_id = p.product_id;