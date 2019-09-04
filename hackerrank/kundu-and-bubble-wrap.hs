-- Author: btjanaka (Bryon Tjanaka)
-- Problem: (HackerRank) kundu-and-bubble-wrap
-- Title: Kundu and Bubble Wrap
-- Link: https://www.hackerrank.com/challenges/kundu-and-bubble-wrap/problem
-- Idea: If we see the problem as a sequence of popping one bubble at a time,
-- then at round i, there is probability (n - i)/n that Kundu pops a bubble.
-- The distribution of hits until Kundu pops a bubble is a geometric
-- distribution, so the mean number of hits before a pop is 1/p or n/(n - i). We
-- sum up the expected pops and have our answer.
-- Difficulty: medium
-- Tags: probability, math
compute :: Double -> Double -> Double
compute _ 0 = 1
compute n i = n / (n - i) + compute n (i - 1)

main :: IO ()
main = do
  line <- getLine
  let [n, m] = map (read :: String -> Double) $ words line
  print $ compute (n * m) ((n * m) - 1)
