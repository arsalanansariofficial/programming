select x,
  y,
  z,
  coalesce(
    case
      when abs(x + y) > abs(z)
      and abs(y + z) > abs(x)
      and abs(z + x) > abs(y) then 'Yes'
      when abs(x + y) < abs(z) || abs(y + z) < abs(x) || abs(z + x) < abs(y) then 'No'
    end,
    'No'
  ) as triangle
from triangle;