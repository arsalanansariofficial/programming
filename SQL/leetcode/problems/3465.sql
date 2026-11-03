-- 3465. Find Products With Valid Serial Numbers
-- https://leetcode.com/problems/find-products-with-valid-serial-numbers/description/
SELECT
  product_id,
  product_name,
  description
FROM
  Products
WHERE
  REGEXP_LIKE (
    description,
    '(^|[^A-Za-z0-9_])SN[0-9]{4}-[0-9]{4}([^A-Za-z0-9_]|$)',
    'c'
  )
ORDER BY
  product_id;
