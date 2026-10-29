-- 1407. Top Travellers
-- https://leetcode.com/problems/top-travellers/
select
  u.name as name,
  sum(coalesce(r.distance, 0)) as travelled_distance
from
  users as u
  left join rides as r on u.id = r.user_id
group by
  u.id
order by
  travelled_distance desc,
  name asc;
