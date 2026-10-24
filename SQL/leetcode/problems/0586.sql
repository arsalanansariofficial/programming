-- 586. Customer Placing the Largest Number of Orders
-- https://leetcode.com/problems/customer-placing-the-largest-number-of-orders/
select
  customer_number
from
  orders
group by
  customer_number
order by
  count(customer_number) desc
limit
  1;
