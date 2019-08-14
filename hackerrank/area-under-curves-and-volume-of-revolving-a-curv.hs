-- Author: btjanaka (Bryon Tjanaka)
-- Problem: (HackerRank) area-under-curves-and-volume-of-revolving-a-curv
-- Title: Area Under Curves and Volume of a Revolving Curve
-- Link: https://www.hackerrank.com/challenges/area-under-curves-and-volume-of-revolving-a-curv/problem
-- Idea: integration
-- Difficulty: easy
-- Tags: fp, math
import Data.List
import Text.Printf (printf)

-- This function returns a list [area, volume].
solve :: Double -> Double -> [Double] -> [Double] -> [Double]
solve l r a b =
  map sum . transpose $
  [ let radius = (sum $ zipWith (*) a (map (x **) b))
        height = 0.001
     in [radius * height, pi * radius ^ 2 * height]
  | x <- [l,(l + 0.001) .. r]
  ]

main :: IO ()
main =
  getContents >>=
  mapM_ (printf "%.1f\n") .
  (\[a, b, [l, r]] -> solve l r a b) .
  map (map (read :: String -> Double) . words) . lines
