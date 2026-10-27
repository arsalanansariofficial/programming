-- 1084. Sales Analysis III
-- https://leetcode.com/problems/sales-analysis-iii/
select distinct
  p.product_id,
  p.product_name
from
  sales as s
  left join product as p on p.product_id = s.product_id
group by
  p.product_id
having
  min(sale_date) >= '2019-01-01'
  and max(sale_date) <= '2019-03-31';
