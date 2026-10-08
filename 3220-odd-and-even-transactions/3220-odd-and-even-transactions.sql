# Write your MySQL query statement below
Select transaction_date,
 Sum(case when amount %2 !=0 then amount else 0 END) As odd_sum, 
 Sum(case when amount %2 =0 then amount else 0 END) As even_sum
 From transactions
 Group By transaction_date order by transaction_date;
 
