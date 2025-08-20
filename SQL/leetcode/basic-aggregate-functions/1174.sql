with first_orders as (
  select d1.customer_id as customer_id,
    min(d1.order_date) as first_order
  from delivery as d1
    join delivery as d2 on d2.customer_id = d1.customer_id
  group by d1.customer_id
)
select round(
    (
      count(first_orders.customer_id) / customers.customers
    ) * 100,
    2
  ) as immediate_percentage
from first_orders
  join delivery
  join (
    select count(distinct customer_id) as customers
    from delivery
  ) as customers on delivery.customer_id = first_orders.customer_id
  and delivery.customer_pref_delivery_date = first_orders.first_order;