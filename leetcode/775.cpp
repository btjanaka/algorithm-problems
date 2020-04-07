// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 775
// Title: Global and Local Inversions
// Link: https://leetcode.com/problems/global-and-local-inversions
// Idea: User mergesort for counting global inversions. Counting local
// inversions is trivial.
// Difficulty: medium
// Tags: sorting
class Solution {
 public:
  int countLocalInversions(vector<int>& A) {
    int res = 0;
    for (int i = 0; i < A.size() - 1; ++i) res += A[i] > A[i + 1];
    return res;
  }

  // Use mergesort to count inversions
  // L and R are inclusive
  int countGlobalInversions(vector<int>& A, vector<int>& buf, int L, int R) {
    if (L == R || R < L) return 0;

    int res = countGlobalInversions(A, buf, L, (L + R) / 2) +
              countGlobalInversions(A, buf, (L + R) / 2 + 1, R);

    for (int i = L; i <= R; ++i) buf[i] = A[i];

    int A_i = L, L_i = L, R_i = (L + R) / 2 + 1;
    while (A_i <= R) {
      if (L_i <= (L + R) / 2 && R_i <= R) {
        if (buf[L_i] <= buf[R_i]) {
          A[A_i++] = buf[L_i];
          ++L_i;
        } else {
          res += (L + R) / 2 - L_i + 1;
          A[A_i++] = buf[R_i];
          ++R_i;
        }
      } else if (R_i <= R) {
        A[A_i++] = buf[R_i];
        ++R_i;
      } else {
        A[A_i++] = buf[L_i];
        ++L_i;
      }
    }

    return res;
  }

  bool isIdealPermutation(vector<int>& A) {
    vector<int> sorted = A;  // because countGlobal modifies in place
    vector<int> buf = sorted;
    int local = countLocalInversions(A);
    int global = countGlobalInversions(sorted, buf, 0, A.size() - 1);
    return local == global;
  }
};
