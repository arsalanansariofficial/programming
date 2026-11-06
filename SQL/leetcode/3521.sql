select
  p1.product_id as product1_id,
  p2.product_id as product2_id,
  pi1.category as product1_category,
  pi2.category as product2_category,
  count(*) as customer_count
from
  productpurchases as p1
  join productpurchases as p2 on p2.user_id = p1.user_id
  and p2.product_id > p1.product_id
  join productinfo as pi1 on pi1.product_id = p1.product_id
  join productinfo as pi2 on pi2.product_id = p2.product_id
group by
  product1_id,
  product2_id
having
  customer_count >= 3
order by
  customer_count desc,
  product1_id,
  product2_id;
