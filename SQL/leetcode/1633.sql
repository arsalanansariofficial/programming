select
  contests.contest_id as contest_id,
  round(
    (
      count(
        case
          when users.user_id = contests.user_id then 1
        end
      ) / count(distinct users.user_id)
    ) * 100,
    2
  ) as percentage
from
  users
  join register as contests
group by
  contests.contest_id
order by
  percentage desc,
  contests.contest_id
