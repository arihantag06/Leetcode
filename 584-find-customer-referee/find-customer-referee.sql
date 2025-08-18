# Write your MySQL query statement below
SELECT name from Customer WHERE referee_id!=2 OR ISNULL(referee_id)=TRUE;