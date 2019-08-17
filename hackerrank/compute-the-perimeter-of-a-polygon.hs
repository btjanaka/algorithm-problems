-- Author: btjanaka (Bryon Tjanaka)
-- Problem: (HackerRank) compute-the-perimeter-of-a-polygon
-- Title: Compute the Perimeter of a Polygon
-- Link: https://www.hackerrank.com/challenges/lambda-march-compute-the-perimeter-of-a-polygon/problem
-- Idea: (implementation)
-- Difficulty: easy
-- Tags: computational-geometry, fp
import           Control.Monad

-- Keep track of current length and previous point
lengthAccumulator :: (Double, [Double]) -> [Double] -> (Double, [Double])
lengthAccumulator (d, [x1, y1]) [x2, y2] =
  (d + (sqrt $ (x2 - x1) ^ 2 + (y2 - y1) ^ 2), [x2, y2])

main = do
  n       <- readLn :: IO Int
  ptsText <- getContents
  let pts = map (map (read :: String -> Double)) $ map words $ lines ptsText
  print $ fst $ foldl lengthAccumulator (0.0, head pts) (pts ++ [head pts])
