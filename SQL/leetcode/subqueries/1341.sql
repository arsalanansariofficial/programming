select results
from (
    select u.name as results
    from movierating mr
      join users u on mr.user_id = u.user_id
    group by u.name
    order by count(*) desc,
      u.name
    limit 1
  ) as top_user
union all
select results
from (
    select m.title as results
    from movierating mr
      join movies m on mr.movie_id = m.movie_id
    where mr.created_at between '2020-02-01' and '2020-02-29'
    group by m.movie_id,
      m.title
    order by avg(mr.rating) desc,
      m.title
    limit 1
  ) as top_movie;