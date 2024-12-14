select a1.machine_id,
  COALESCE(round(avg(a2.timestamp - a1.timestamp), 3), 0)
from activity as a1
  join activity as a2 on a2.machine_id = a1.machine_id
  and a2.process_id = a1.process_id
  and a1.activity_type = 'start'
  and a2.activity_type = 'end'
group by a1.machine_id;