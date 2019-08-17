-- Author: btjanaka (Bryon Tjanaka)
-- Problem: (HackerRank) super-queens-on-a-chessboard
-- Title: Super Queens on a Chessboard
-- Link: https://www.hackerrank.com/challenges/super-queens-on-a-chessboard/problem
-- Idea: Same as regular n-queens problem, but keep track of two rows at a time
-- because of the knight. Use bitsets to store occupied rows for better
-- efficiency.
-- Difficulty: medium
-- Tags: n-queens, recursion, fp
import           Data.Bits
import qualified Data.Set                      as Set
import           Debug.Trace

setBitBounded lo hi n i = if i <= hi && i >= lo then setBit n i else n

-- for debugging
printBits x
  | x == 0    = ""
  | otherwise = (if testBit x 0 then "1" else "0") ++ printBits (shift x (-1))

-- Goes across the board from left to right. At the same time, we keep track of
-- bitsets that tell us what squares are occupied in this column and the next as
-- a result of row attacks, left diagonal (bottom left to top right) attacks,
-- right diagaonal (top left to bottom right) attacks, and knight attacks. Note
-- there have to be two columns because of knight moves. For numbering, the
-- board is seen as going left to right and bottom to top.
nSuperQueens
  :: Int -> Int -> (Int, Int) -> (Int, Int) -> (Int, Int) -> (Int, Int) -> Int
nSuperQueens col n (row, row') (leftd, leftd') (rightd, rightd') (knight, knight')
  | col == n
  = 1
  | otherwise
  = sum
    [ if testBit row r
         || testBit leftd  r
         || testBit rightd r
         || testBit knight r
      then
        0
      else
        let setValidRowBit = setBitBounded 0 (n - 1)
        in
          nSuperQueens
            (col + 1)
            n
            (setBit row' r, setBit row' r)
            (let newLeftd = setValidRowBit leftd' (r + 1)
             in  (newLeftd, shiftL newLeftd 1)
            )
            (let newRightd = setValidRowBit rightd' (r - 1)
             in  (newRightd, shiftR newRightd 1)
            )
            ( setValidRowBit (setValidRowBit knight' (r - 2)) (r + 2)
            , setValidRowBit (setValidRowBit 0 (r - 1))       (r + 1)
            )
    | r <- [0 .. n - 1]
    ]

main = do
  n <- readLn :: IO Int
  print $ nSuperQueens 0 n (0, 0) (0, 0) (0, 0) (0, 0)
