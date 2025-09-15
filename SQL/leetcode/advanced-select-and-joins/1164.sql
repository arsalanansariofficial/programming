-- using join
with changed_before as (
  select p1.product_id as product_id,
    new_price as price
  from products as p1
    join (
      select product_id,
        max(change_date) as change_date
      from products as p2
      where change_date <= '2019-08-16'
      group by product_id
    ) as p2 on p2.change_date = p1.change_date
    and p2.product_id = p1.product_id
  group by p1.product_id
)
select products.product_id as product_id,
  case
    when changed_before.price is not null then changed_before.price
    when changed_before.price is null then 10
  end as price
from products
  left join changed_before on changed_before.product_id = products.product_id
group by products.product_id;
-- using union all
select product_id,
  10 as price
from products
group by product_id
having min(change_date) > '2019-08-16'
union all
select product_id,
  new_price as price
from products
where (product_id, change_date) in (
    select product_id,
      max(change_date) as change_date
    from products
    where change_date <= '2019-08-16'
    group by product_id
  )
group by product_id;