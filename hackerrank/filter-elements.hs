-- Author: btjanaka (Bryon Tjanaka)
-- Problem: (HackerRank) filter-elements
-- Title: Filter Elements
-- Link: https://www.hackerrank.com/challenges/filter-elements/problem
-- Idea: (implementation)
-- Difficulty: easy
-- Tags: fp, recursion
import           Control.Monad
import qualified Data.IntMap.Strict            as IntMap
import           Data.List.Split
import           Data.Maybe

filterElements :: [Int] -> Int -> IntMap.IntMap Int -> [Int] -> [Int]
-- Do the actual filtering in the base case
filterElements [] k counts reversedNums =
  reverse $ filter (\num -> counts IntMap.! num >= k) reversedNums
-- Simply add elements here
filterElements (x : xs) k counts reversedNums = filterElements
  xs
  k
  (IntMap.insertWith (+) x 1 counts)
  (if isNothing $ IntMap.lookup x counts then x : reversedNums else reversedNums
  )

lineToInts :: String -> [Int]
lineToInts s = map read $ splitOn " " s

main = do
  t <- readLn :: IO Int
  forM_ [1 .. t] $ \i -> do
    params <- getLine
    a      <- getLine
    let [n, k] = lineToInts params
        result = filterElements (lineToInts a) k IntMap.empty []
    putStrLn $ if null result then "-1" else unwords $ map show result
