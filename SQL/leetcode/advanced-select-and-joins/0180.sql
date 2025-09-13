select first.num as ConsecutiveNums
from logs as first
  join logs as second on second.num = first.num
  and second.id = first.id + 1
  join logs as third on third.num = first.num
  and third.id = first.id + 2
group by first.num;