-- Author: btjanaka (Bryon Tjanaka)
-- Problem: (HackerRank) prefix-compression
-- Title: Prefix Compression
-- Link: https://www.hackerrank.com/challenges/prefix-compression/problem
-- Idea: (implementation)
-- Difficulty: easy
-- Tags: fp
import Control.Monad

findPrefix :: [Char] -> [Char] -> [[Char]]
findPrefix x "" = ["", x, ""]
findPrefix "" y = ["", "", y]
findPrefix (x:xs) (y:ys) =
  if x == y
    then let result = findPrefix xs ys
          in (x : (head result)) : (tail result)
    else ["", x : xs, y : ys]

main = do
  x <- getLine
  y <- getLine
  let res = findPrefix x y
  forM_ res $ \s -> do putStrLn $ (show $ length s) ++ " " ++ s
