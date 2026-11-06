with
  sales_with_season as (
    select
      category,
      quantity,
      price,
      case
        when month (s.sale_date) in (12, 1, 2) then 'Winter'
        when month (s.sale_date) in (3, 4, 5) then 'Spring'
        when month (s.sale_date) in (6, 7, 8) then 'Summer'
        else 'Fall'
      end as season
    from
      sales as s
      join products as p on p.product_id = s.product_id
  ),
  category_totals as (
    select
      season,
      category,
      sum(quantity) as total_quantity,
      sum(quantity * price) as total_revenue
    from
      sales_with_season
    group by
      season,
      category
  ),
  ranked as (
    select
      season,
      category,
      total_quantity,
      total_revenue,
      row_number() over (
        partition by
          season
        order by
          total_quantity desc,
          total_revenue desc,
          category
      ) as rank_number
    from
      category_totals
  )
select
  season,
  category,
  total_quantity,
  total_revenue
from
  ranked
where
  rank_number = 1
order by
  season;
