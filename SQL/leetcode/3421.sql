select distinct
  *
from
  (
    select
      student_id,
      subject,
      first_value (score) over (
        partition by
          student_id,
          subject
        order by
          exam_date
      ) as first_score,
      first_value (score) over (
        partition by
          student_id,
          subject
        order by
          exam_date desc
      ) as latest_score
    from
      scores
  ) as students_with_improvements
where
  first_score < latest_score
order by
  student_id,
  subject;
