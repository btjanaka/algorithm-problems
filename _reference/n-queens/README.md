# N Queens

Attempts to _quickly_ count the number of solutions to n-queens. See
`n-queens.cpp` for a more basic solution to the problem, and see
`n-queens-optimized.cpp` for a more optimized version. Optimizations include:

- Only calculating half of the solutions, i.e. solutions with the first queen in
  the top half of the board.
- Multithreading the calculation, i.e. spawning a thread for each position of
  the first queen.

## Usage

Build the binaries:

```bash
make
```

And run either of them:

```bash
n-queens [N]
n-queens-optimized [N]
```

Where `N` is the size of the board.

## Benchmarks

Run on an 8th-gen i7 machine with 8 cores.

| n   | wall time (s) |
| :-- | ------------: |
| 1   |   0.000243728 |
| 2   |   0.000345454 |
| 3   |   0.000567031 |
| 4   |   0.000283245 |
| 5   |   0.000234102 |
| 6   |   0.000575749 |
| 7   |   0.000937274 |
| 8   |   0.000920208 |
| 9   |   0.000491408 |
| 10  |   0.001120468 |
| 11  |   0.001296742 |
| 12  |   0.001704815 |
| 13  |   0.009593300 |
| 14  |   0.036787850 |
| 15  |   0.159160947 |
| 16  |   0.944027837 |
| 17  |   8.258171572 |
| 18  |  92.950227574 |
| 19  | 754.883511774 |

## Credits

Basic implementation in `n-queens.cpp` adapted from _Competitive Programming 3_
by Steven and Felix Halim.

Many thanks to Ofek Gila ([@ofekih](https://github.com/ofekih)) for various
optimization ideas.
