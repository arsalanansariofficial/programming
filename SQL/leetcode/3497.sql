select
  a1.user_id,
  round(avg(a2.activity_duration), 2) as trial_avg_duration,
  round(avg(a3.activity_duration), 2) as paid_avg_duration
from
  useractivity as a1
  join useractivity as a2 on a2.user_id = a1.user_id
  and a2.activity_type = 'free_trial'
  join useractivity as a3 on a3.user_id = a1.user_id
  and a3.activity_type = 'paid'
group by
  user_id
having
  sum(if (a1.activity_type = 'paid', 1, 0)) > 0
order by
  a1.user_id;
