select
  users.user_id as buyer_id,
  join_date,
  count(order_id) as orders_in_2019
from
  users
  left join orders on buyer_id = user_id
  and order_date between '2019-01-01' and '2019-12-31'
group by
  user_id;
