create function getnthhighestsalary(n int) returns int
begin
  declare offset int;
  set offset = n - 1;

  return (
    select
        distinct salary
    from
        employee
    order by
        salary desc
    limit
        offset, 1
  );
end
