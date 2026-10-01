/* Write your PL/SQL query statement below */
    with ranked_salaries as (
        select 
            d.name as Department, 
            e.name as Employee, 
            e.salary as Salary, 
            dense_rank() over (
                partition by d.name order by e.salary desc
            ) as rnk
        from Employee e 
        Join Department d 
        on e.departmentId = d.id
    )
    select Department, Employee, Salary 
    from ranked_salaries 
    where rnk = 1;
    

