-- Author: btjanaka (Bryon Tjanaka)
-- Problem: (HackerRank) eval-ex
-- Title: Evaluating e^x
-- Link: https://www.hackerrank.com/challenges/eval-ex/problem
-- Idea: (implementation)
-- Difficulty: easy
-- Tags: fp
{-# LANGUAGE FlexibleInstances, UndecidableInstances,
  DuplicateRecordFields #-}

module Main where

import           Control.Monad
import           Data.Array
import           Data.Bits
import           Data.List
import           Data.List.Split
import           Data.Set
import           Debug.Trace
import           System.Environment
import           System.IO
import           System.IO.Unsafe

factorial :: Integer -> Integer
factorial n | n <= 1    = 1
            | otherwise = n * (factorial $ n - 1)

e :: Double -> Int -> Double
e x 0 = 1
e x n =
  x ** (fromIntegral n) / (fromIntegral $ factorial $ toInteger n) + e x (n - 1)

main :: IO ()
main = do
  n <- readLn :: IO Int
  forM_ [1 .. n] $ \n_itr -> do
    x <- readLn :: IO Double
    putStrLn $ show $ e x 9
