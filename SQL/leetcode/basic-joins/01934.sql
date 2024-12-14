select s.user_id,
  COALESCE(
    round(
      avg(
        CASE
          WHEN c.action = 'confirmed' THEN 1
          ELSE 0
        END
      ),
      3
    ),
    0
  ) as confirmation_rate
from signups as s
  left join confirmations as c on c.user_id = s.user_id
group by s.user_id;