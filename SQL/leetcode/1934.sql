select
  s.user_id,
  coalesce(
    round(
      avg(
        case
          when c.action = 'confirmed' then 1
          else 0
        end
      ),
      3
    ),
    0
  ) as confirmation_rate
from
  signups as s
  left join confirmations as c on c.user_id = s.user_id
group by
  s.user_id;
