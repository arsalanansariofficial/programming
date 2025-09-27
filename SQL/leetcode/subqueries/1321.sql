with dailytotals as (
  select visited_on,
    sum(amount) as daily_amount
  from customer
  group by visited_on
),
rollingwindow as (
  select visited_on,
    sum(daily_amount) over (
      order by visited_on rows between 6 preceding and current row
    ) as amount
  from dailytotals
)
select visited_on,
  amount,
  round(amount / 7.0, 2) as average_amount
from rollingwindow
where visited_on >= (
    select min(visited_on) + interval 6 day
    from customer
  )
order by visited_on;