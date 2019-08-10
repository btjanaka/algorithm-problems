-- Author: btjanaka (Bryon Tjanaka)
-- Problem: (HackerRank) the-sums-of-powers
-- Title: The Sums of Powers
-- Link: https://www.hackerrank.com/challenges/functional-programming-the-sums-of-powers/problem
-- Idea: basic recursion probability
-- Difficulty: easy
-- Tags: fp, recursion
sumsOfPowers :: Int -> Int -> Int -> Int
sumsOfPowers x n lastInt
  | x < 0 = 0
  | x == 0 = 1
  | otherwise =
    sum
      [ sumsOfPowers (x - i ^ n) n i
      | i <- takeWhile (\y -> y ^ n <= x) [lastInt + 1 ..]
      ]

main = do
  x <- readLn :: IO Int
  n <- readLn :: IO Int
  putStrLn $ show $ sumsOfPowers x n 0
