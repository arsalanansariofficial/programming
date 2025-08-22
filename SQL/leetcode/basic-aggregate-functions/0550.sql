with first_login as (
  select player_id,
    min(event_date) as first_login
  from activity
  group by player_id
),
next_login as (
  select activity.player_id as player_id,
    first_login.first_login + 1 as next_day
  from activity
    join first_login on first_login.player_id = activity.player_id
    and activity.event_date = date_add(first_login.first_login, interval 1 day)
)
select round(
    count(next_login.player_id) / count(first_login.player_id),
    2
  ) as fraction
from first_login
  left join next_login on next_login.player_id = first_login.player_id;