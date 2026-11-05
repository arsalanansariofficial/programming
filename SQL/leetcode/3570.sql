select
  b.book_id as book_id,
  b.title as title,
  b.author as author,
  b.genre as genre,
  b.publication_year as publication_year,
  count(
    case
      when return_date is null then 1
    end
  ) as current_borrowers
from
  library_books as b
  join borrowing_records as br on br.book_id = b.book_id
group by
  book_id,
  title,
  author,
  genre,
  publication_year,
  total_copies
having
  current_borrowers = total_copies
order by
  current_borrowers desc,
  title;
