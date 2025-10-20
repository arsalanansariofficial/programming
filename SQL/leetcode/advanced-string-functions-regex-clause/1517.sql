select user_id,
  name,
  mail
from users
where regexp_like(
    mail,
    '^[A-Za-z][A-Za-z0-9._-]*@leetcode\\.com$',
    'c'
  );