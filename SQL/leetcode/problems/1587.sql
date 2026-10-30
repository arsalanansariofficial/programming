-- 1587. Bank Account Summary II
-- https://leetcode.com/problems/bank-account-summary-ii/description/
select
  name,
  sum(transactions.amount) as balance
from
  transactions
  join users on users.account = transactions.account
group by
  transactions.account
having
  balance > 10000;
