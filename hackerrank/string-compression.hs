-- Author: btjanaka (Bryon Tjanaka)
-- Problem: (HackerRank) string-compression
-- Title: String Compression
-- Link: https://www.hackerrank.com/challenges/string-compression/problem
-- Idea: (implementation)
-- Difficulty: easy
-- Tags: fp
compress :: [Char] -> [Char]
compress s =
  concat
    $ map (\(ch, count) -> if count == 1 then [ch] else ch : (show count))
    $ tail
    $ reverse
    $ foldl
        (\(recent_letter_and_count : remaining) ch ->
          if fst recent_letter_and_count == ch
            then
              (fst recent_letter_and_count, snd recent_letter_and_count + 1)
                : remaining
            else (ch, 1) : recent_letter_and_count : remaining
        )
        [('\0', 0)]
        s

main = do
  s <- getLine
  putStrLn $ compress s
