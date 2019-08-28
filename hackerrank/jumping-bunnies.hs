-- Author: btjanaka (Bryon Tjanaka)
-- Problem: (HackerRank) jumping-bunnies
-- Title: Jumping Bunnies
-- Link: https://www.hackerrank.com/challenges/jumping-bunnies/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign
-- Idea: LCM of all the numbers.
-- Difficulty: easy
-- Tags: fp
main = do
  n <- readLn :: IO Int
  jText <- getLine
  let j = map (read :: String -> Integer) $ words jText
  print $ foldl1 (\cur x -> lcm cur x) j
