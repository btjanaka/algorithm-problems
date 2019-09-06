-- Author: btjanaka (Bryon Tjanaka)
-- Problem: (HackerRank) jumping-bunnies
-- Title: Jumping Bunnies
-- Link: https://www.hackerrank.com/challenges/jumping-bunnies/problem
-- Idea: LCM of all the numbers.
-- Difficulty: easy
-- Tags: fp
main = do
  n <- readLn :: IO Int
  jText <- getLine
  let j = map (read :: String -> Integer) $ words jText
  print $ foldl1 (\cur x -> lcm cur x) j
