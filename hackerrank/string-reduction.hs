-- Author: btjanaka (Bryon Tjanaka)
-- Problem: (HackerRank) string-reduction
-- Title: String Reduction
-- Link: https://www.hackerrank.com/challenges/string-reductions/problem
-- Idea: (implementation)
-- Difficulty: easy
-- Tags: fp
import qualified Data.Set                      as Set

reduceString :: [Char] -> Set.Set Char -> [Char]
reduceString []       _   = []
reduceString (x : xs) cur = if Set.member x cur
  then reduceString xs cur
  else x : reduceString xs (Set.insert x cur)

main = do
  s <- getLine
  putStrLn $ reduceString s Set.empty
