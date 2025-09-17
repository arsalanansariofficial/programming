with running_weight as (
  select *,
    sum(weight) over (
      order by turn rows between unbounded preceding and current row
    ) as cumulative_weight
  from queue
  order by turn
)
select queue.person_name
from queue
  join running_weight on running_weight.person_id = queue.person_id
where cumulative_weight <= 1000
order by cumulative_weight desc
limit 1;