-- Author: btjanaka (Bryon Tjanaka)
-- Problem: (HackerRank) concave-polygon
-- Title: Concave Polygon
-- Link: https://www.hackerrank.com/challenges/lambda-march-concave-polygon/problem
-- Idea: Sort points by polar angle around the point that is at the bottom of
-- the polygon (favoring left points for ties), then check the orientation while
-- going through all consecutive triples.
-- Difficulty: medium
-- Tags: fp, computational-geometry, convex-hull
import Data.List

findBottomLeftMostPoint =
  foldl1
    (\(x, y) (x', y') ->
       if y' < y || (y' == y && x' < x)
         then (x', y')
         else (x, y))

calcOrientation (x1, y1) (x2, y2) (x3, y3) =
  x1 * y2 - x2 * y1 + x3 * y1 - x1 * y3 + x2 * y3 - x3 * y2

-- Go around the whole polygon checking consecutive triples of points - if any
-- have a "right" orientation then the polygon is concave.
-- Input must be points describing polygon in counterclockwise order and start
-- and end with the same point
isConcave [] = False
isConcave [_] = False
isConcave [_, _] = False
isConcave (p1:p2:p3:ccwPoints) =
  (calcOrientation p1 p2 p3 < 0) || isConcave (p2 : p3 : ccwPoints)

dist (x1, y1) (x2, y2) = sqrt $ (x2 - x1) ^ 2 + (y2 - y1) ^ 2

orientationComparer ref@(x0, y0) p1@(x1, y1) p2@(x2, y2) =
  let angle1 = atan2 (y1 - y0) (x1 - x0)
      angle2 = atan2 (y2 - y0) (x2 - x0)
   in if abs (angle2 - angle1) < 1e-6
        then compare (dist ref p1) (dist ref p2)
        else compare angle1 angle2

main = do
  text <- getContents
  let input = lines text
      n = read (head input) :: Int
      points =
        map
          (\s ->
             let [x, y] = map read $ words s
              in (x, y)) $
        tail input :: [(Double, Double)]
      bottomLeftMostPoint@(blx, bly) = findBottomLeftMostPoint points
      ccwPoints =
        sortBy
          (orientationComparer bottomLeftMostPoint)
          (delete bottomLeftMostPoint points)
      polygon = [bottomLeftMostPoint] ++ ccwPoints ++ [bottomLeftMostPoint]
  putStrLn $
    if isConcave polygon
      then "YES"
      else "NO"
