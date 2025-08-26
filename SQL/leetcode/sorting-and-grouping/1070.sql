select sales.product_id,
  first_year,
  quantity,
  price
from sales
  join (
    select product_id,
      min(year) as first_year
    from sales
    group by product_id
  ) as product_first_sales_year on product_first_sales_year.product_id = sales.product_id
  and product_first_sales_year.first_year = sales.year;