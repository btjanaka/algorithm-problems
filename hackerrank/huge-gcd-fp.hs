-- Author: btjanaka (Bryon Tjanaka)
-- Problem: (HackerRank) huge-gcd-fp
-- Title: Huge GCD
-- Link: https://www.hackerrank.com/challenges/huge-gcd-fp/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign
-- Idea: Factor all the numbers in each list then find ones in common.
-- Difficulty: easy
-- Tags: math
import Data.List

-- Returns a list of factors of the given number
factors :: Int -> Int -> [Int]
factors x n
  | x == 1 = []
  | x `mod` n == 0 = n : factors (x `div` n) n
  | otherwise =
    factors
      x
      (if n == 2
         then 3
         else n + 2)

-- Factors all numbers in the list and puts them all in a new list.
allFactors :: [Int] -> [Int]
allFactors xs =
  sort $ do
    i <- xs
    factors i 2

-- Computes gcd from two lists of _sorted_ factors.
gcdFromFactors :: [Int] -> [Int] -> Int
gcdFromFactors [] _ = 1
gcdFromFactors _ [] = 1
gcdFromFactors (x:xs) (y:ys)
  | x == y = (x * gcdFromFactors xs ys) `mod` 1000000007
  | x > y = gcdFromFactors (x : xs) ys
  | otherwise = gcdFromFactors xs (y : ys)

main :: IO ()
main = do
  _ <- readLn :: IO Int -- read but ignore n
  aText <- getLine
  _ <- readLn :: IO Int -- read but ignore m
  bText <- getLine
  let a = map (read :: String -> Int) $ words aText
      b = map (read :: String -> Int) $ words bText
      aFactored = allFactors a
      bFactored = allFactors b
  print $ gcdFromFactors aFactored bFactored
