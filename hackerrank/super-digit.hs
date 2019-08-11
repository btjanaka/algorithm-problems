-- Author: btjanaka (Bryon Tjanaka)
-- Problem: (HackerRank) super-digit
-- Title: Super Digit
-- Link: https://www.hackerrank.com/challenges/super-digit/problem
-- Idea: (implementation)
-- Difficulty: easy
-- Tags: fp, recursion
superDigit :: String -> Int
superDigit n =
  if length n == 1
    then read n
    else superDigit $ show $ sum [read [digit] :: Int | digit <- n]

main = do
  s <- getLine
  let [n, k] = words s
  print $ superDigit $ show $ (read k :: Int) * superDigit n
