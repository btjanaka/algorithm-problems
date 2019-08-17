-- Author: btjanaka (Bryon Tjanaka)
-- Problem: (HackerRank) compute-the-area-of-a-polygon
-- Title: Compute the Area of a Polygon
-- Link: https://www.hackerrank.com/challenges/lambda-march-compute-the-area-of-a-polygon/problem?h_r=next-challenge&h_v=zen
-- Idea: Shoelace Formula - see https://en.wikipedia.org/wiki/Shoelace_formula
-- Difficulty: easy
-- Tags: computation-geometry, fp
import           Data.List

shoelace :: [Double] -> [Double] -> Double
shoelace xs ys =
  0.5
    * (sum (zipWith (*) xs (last ys : ys)) - sum (zipWith (*) (last xs : xs) ys)
      )

main = do
  n       <- readLn :: IO Int
  ptsText <- getContents
  let [xs, ys] =
        transpose
          $ map (map (read :: String -> Double) . words)
          . lines
          $ ptsText
  print $ -shoelace xs ys -- Negative because pts are clockwise
