SELECT contests.contest_id AS contest_id,
  ROUND(
    (
      COUNT(
        CASE
          WHEN users.user_id = contests.user_id THEN 1
        END
      ) / COUNT(DISTINCT users.user_id)
    ) * 100,
    2
  ) AS percentage
FROM users
  JOIN register AS contests
GROUP BY contests.contest_id
ORDER BY percentage desc,
  contests.contest_id