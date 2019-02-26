-- Author: btjanaka (Bryon Tjanaka)
-- Problem: (Hackerrank) Weater Observation Station 5

select min(a.city), length(min(a.city))
from (select b.city, length(b.city)
      from station as b
      where length(b.city) <= all(select length(c.city) from station as c)) as a;

select min(a.city), length(min(a.city))
from (select b.city, length(b.city)
      from station as b
      where length(b.city) >= all(select length(c.city) from station as c)) as a;
