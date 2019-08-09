-- Author: btjanaka (Bryon Tjanaka)
-- Problem: (HackerRank) string-o-permute
-- Title: String-o-Permute
-- Link: https://www.hackerrank.com/challenges/string-o-permute/problem
-- Idea: (implementation)
-- Difficulty: easy
-- Tags: fp
import Control.Monad

swap :: [Char] -> [Char]
swap [] = []
swap [x] = [x] -- Technically don't need to cover this because string is even length
swap (x:y:xs) = y : x : (swap xs)

main = do
  n <- readLn :: IO Int
  forM_ [1 .. n] $ \i -> do
    s <- getLine
    putStrLn $ swap s
