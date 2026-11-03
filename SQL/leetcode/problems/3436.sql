-- 3436. Find Valid Emails
-- https://leetcode.com/problems/find-valid-emails/description/
select
  user_id,
  email
from
  users
where
  email regexp '^[a-za-z0-9_]+@[a-za-z]+[.]com$'
order by
  user_id asc;
