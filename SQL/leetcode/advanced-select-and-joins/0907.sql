with categories as (
  select 'low salary' as category
  union all
  select 'average salary'
  union all
  select 'high salary'
),
category_count as (
  select case
      when income < 20000 then 'low salary'
      when income between 20000 and 50000 then 'average salary'
      when income > 50000 then 'high salary'
    end as category,
    count(account_id) as account_count
  from accounts
  group by category
)
select categories.category as category,
  coalesce(account_count, 0) as accounts_count
from categories
  left join category_count on category_count.category = categories.category;