select coalesce(max(num), null) as num
from (
    select num
    from mynumbers
    group by num
    having count(*) = 1
  ) as filtered;