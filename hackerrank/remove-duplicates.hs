-- Author: btjanaka (Bryon Tjanaka)
-- Problem: (HackerRank) remove-duplicates
-- Title: Remove Duplicates
-- Link: https://www.hackerrank.com/challenges/remove-duplicates/problem
-- Idea: Maintain a set of seen characters.
-- Difficulty: easy
-- Tags: string, list, implementation
import qualified Data.Set as Set

main :: IO ()
main = do
  s <- getLine
  putStrLn $
    reverse $
    snd $
    foldl
      (\(seen, cur) ch ->
         if Set.member ch seen
           then (seen, cur)
           else (Set.insert ch seen, ch : cur))
      (Set.empty, [])
      s
