-- Author: btjanaka (Bryon Tjanaka)
-- Problem: (HackerRank) convex-hull
-- Title: Convex Hull
-- Link: https://www.hackerrank.com/challenges/convex-hull-fp/problem
-- Idea: Convex hull algorithm - use Graham Scan - sort points by polar angle
-- around bottom left point then go around.
-- Difficulty: medium
-- Tags: fp, computational-geometry, convex-hull
import           Data.List
import           Debug.Trace
import           Text.Printf

findBottomLeftMostPoint = foldl1
  (\(x, y) (x', y') ->
    if y' < y || (y' == y && x' < x) then (x', y') else (x, y)
  )

dist (x1, y1) (x2, y2) = sqrt $ (x2 - x1) ^ 2 + (y2 - y1) ^ 2

orientationComparer ref@(x0, y0) p1@(x1, y1) p2@(x2, y2) =
  let angle1 = atan2 (y1 - y0) (x1 - x0)
      angle2 = atan2 (y2 - y0) (x2 - x0)
  in  if abs (angle2 - angle1) < 1e-6
        then compare (dist ref p1) (dist ref p2)
        else compare angle1 angle2

calcOrientation (x1, y1) (x2, y2) (x3, y3) =
  x1 * y2 - x2 * y1 + x3 * y1 - x1 * y3 + x2 * y3 - x3 * y2

addPoint :: [(Double, Double)] -> (Double, Double) -> [(Double, Double)]
addPoint []     v = [v]
addPoint vs@[p] v = v : vs
addPoint vs@(p1 : p2 : ps) v =
  if calcOrientation p2 p1 v < 0 then addPoint (p2 : ps) v else v : vs

convexHull = foldl addPoint []

calcHullLength :: [(Double, Double)] -> Double
calcHullLength points =
  let base = findBottomLeftMostPoint points
      polygon =
          [base]
            ++ sortBy (orientationComparer base) (delete base points)
            ++ [base]
      hull = convexHull polygon
  in  traceShow polygon $ traceShow hull $ sum $ zipWith dist
                                                         (init hull)
                                                         (tail hull)

main :: IO ()
main = do
  n       <- readLn :: IO Int
  content <- getContents
  let points =
        map (\[x, y] -> (x, y))
          . map (map (read :: String -> Double))
          . map words
          . lines
          $ content
      ans = calcHullLength points
  printf "%.1f\n" ans
