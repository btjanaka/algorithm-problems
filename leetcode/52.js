// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 52
// Title: N-Queens II
// Link: https://leetcode.com/problems/n-queens-ii/
// Idea: This implementation uses an "engine" that keeps track of an internal
// state. The step() function is repeatedly called to advance the state and find
// all solutions.
// Difficulty: medium
// Tags: complete-search
class NQueensEngine {
  constructor(n) {
    this.n = undefined;
    this.queens = undefined;
    this.curQueen = undefined;
    this.justBacktracked = undefined;
    this.reset(n);
  }

  // Resets the board with n new queens.
  reset = n => {
    this.n = n;
    this.queens = [];
    for (let i = 0; i < n; ++i) this.queens.push(0);
    this.curQueen = 0;
    this.justBacktracked = false;
  };

  // Returns true if a solution was found.
  step = () => {
    // Check if current position conflicts, but only if we did not just
    // backtrack (there is no need to check for conflicts if we just
    // backtracked).
    let conflict = false;
    if (!this.justBacktracked) {
      for (let i = 0; i < this.curQueen; ++i) {
        let sameRow = this.queens[i] == this.queens[this.curQueen];
        let sameDiag1 =
          this.queens[i] - this.queens[this.curQueen] == i - this.curQueen;
        let sameDiag2 =
          this.queens[i] - this.queens[this.curQueen] == this.curQueen - i;

        if (sameRow || sameDiag1 || sameDiag2) {
          conflict = true;
          break;
        }
      }
    }

    if (!conflict && !this.justBacktracked) {
      // If no conflict, advance the queen.
      ++this.curQueen;

      // If curQueen is now at the end, a solution was found. Furthermore, we
      // should decrement curQueen to continue the search.
      if (this.curQueen == this.n) {
        --this.curQueen;
        this.justBacktracked = true;
        return true;
      }

      return false;
    } else {
      // Otherwise, advance in the current column.
      ++this.queens[this.curQueen];
      this.justBacktracked = false;

      // Reset this column and move curQueen back if done checking.
      if (this.queens[this.curQueen] == this.n) {
        this.queens[this.curQueen] = 0;
        --this.curQueen;
        this.justBacktracked = true;
      }

      return false;
    }
  };

  // Returns true if done searching. This happens when curQueen is set to -1
  // because the step function is unable to move the queen in column 0 anymore.
  done = () => {
    return this.curQueen == -1;
  };
}

/**
 * @param {number} n
 * @return {number}
 */
let totalNQueens = function (n) {
  let engine = new NQueensEngine(n);
  let tot = 0;
  while (!engine.done()) {
    if (engine.step()) {
      ++tot;
    }
  }
  return tot;
};
