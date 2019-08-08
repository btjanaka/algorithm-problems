-- Author: btjanaka (Bryon Tjanaka)
-- Problem: (HackerRank) pascals-triangle
-- Title: Pascal's Triangle
-- Link: https://www.hackerrank.com/challenges/pascals-triangle/problem
-- Idea: (implementation)
-- Difficulty: easy
-- Tags: fp
import Data.List

pascal :: Int -> [[Int]]
pascal 1 = [[1]]
pascal n =
  let others = pascal $ n - 1
      last = head others
   in ([1] ++ map sum (transpose [init last, tail last]) ++ [1]) : others

main :: IO ()
main = do
  n <- readLn :: IO Int
  mapM_ (putStrLn . unwords . map show) (reverse $ pascal n)
