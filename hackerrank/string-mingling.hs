-- Author: btjanaka (Bryon Tjanaka)
-- Problem: (HackerRank) string-mingling
-- Title: String Mingling
-- Link: https://www.hackerrank.com/challenges/string-mingling/problem
-- Idea: (implementation)
-- Difficulty: easy
-- Tags: fp
import           Data.List

main = do
  p <- getLine
  q <- getLine
  putStrLn $ concat $ transpose [p, q]
