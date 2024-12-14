select stu.student_id,
  stu.student_name,
  sub.subject_name,
  count(exm.student_id)
from students as stu
  join subjects as sub
  left join examinations as exm on exm.student_id = stu.student_id
  and exm.subject_name = sub.subject_name
group by stu.student_id,
  stu.student_name,
  sub.subject_name,
  exm.subject_name
order by stu.student_id,
  sub.subject_name;