-- Author: btjanaka (Bryon Tjanaka)
-- Problem: (HackerRank) sequence-full-of-colors
-- Title: Sequence Full Of Colors
-- Link: https://www.hackerrank.com/challenges/sequence-full-of-colors/problem
-- Idea: Basic recursion
-- Difficulty: easy
-- Tags: fp, recursion
import Control.Monad

checkFull :: String -> Int -> Int -> Int -> Int -> Bool
checkFull "" r g y b = r == g && y == b
checkFull (x:xs) r g y b =
  let rgdiff = max r g - min r g
      ybdiff = max y b - min y b
      midCriteria = rgdiff <= 1 && ybdiff <= 1
      r2 =
        if x == 'R'
          then r + 1
          else r
      g2 =
        if x == 'G'
          then g + 1
          else g
      y2 =
        if x == 'Y'
          then y + 1
          else y
      b2 =
        if x == 'B'
          then b + 1
          else b
   in midCriteria && checkFull xs r2 g2 y2 b2

main = do
  n <- readLn :: IO Int
  forM_ [1 .. n] $ \i -> do
    s <- getLine
    print $ checkFull s 0 0 0 0
