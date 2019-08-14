-- Author: btjanaka (Bryon Tjanaka)
-- Problem: (HackerRank) functions-or-not
-- Title: Functions or Not?
-- Link: https://www.hackerrank.com/challenges/functions-or-not/problem
-- Idea: Functions map each value to only one other value.
-- Difficulty: easy
-- Tags: fp
import Control.Monad
import qualified Data.Map as Map

readLines :: Int -> IO [String]
readLines n
  | n == 0 = return []
  | otherwise = do
    s <- getLine
    otherLines <- readLines (n - 1)
    return $ s : otherLines

functionChecker :: (Bool, Map.Map Int Int) -> [Int] -> (Bool, Map.Map Int Int)
functionChecker (fails, m) [k, v] =
  (fails || (Map.member k m && (Map.!) m k /= v), Map.insert k v m)

main = do
  t <- readLn :: IO Int
  forM_ [1 .. t] $ \ca -> do
    n <- readLn :: IO Int
    funcText <- readLines n
    let mappings = map (map (read :: String -> Int) . words) funcText
    putStrLn $
      if fst $ foldl functionChecker (False, Map.empty) mappings
        then "NO"
        else "YES"
