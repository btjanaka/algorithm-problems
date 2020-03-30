-- Author: btjanaka (Bryon Tjanaka)
-- Problem: (Hackerrank) Weather Observation Station 4

SELECT count(c.city) - count(distinct c.city)
FROM station as c
