// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) arcade
// Title: Arcade
// Link: https://open.kattis.com/problems/arcade
// Idea: Express each expected value as a linear equation. Then we have a system
// of H linear equations. We can use Halim's Gaussian Elimination implementation
// to solve.
// Difficulty: medium
// Tags: math, numeric-algorithms, probability
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

// Solves an augmented matrix by Gaussian elimination.
vector<double> gaussian(vector<vector<double>>& mat, int n) {
  int i, j, k, l;
  double t;
  vector<double> x(n);

  for (j = 0; j < n - 1; ++j) {
    l = j;
    for (i = j + 1; i < n; ++i) {
      if (fabs(mat[i][j]) > fabs(mat[l][j])) l = i;
    }
    for (k = j; k <= n; ++k) {
      t = mat[j][k], mat[j][k] = mat[l][k], mat[l][k] = t;
    }
    for (i = j + 1; i < n; ++i) {
      for (k = n; k >= j; --k) {
        mat[i][k] -= mat[j][k] * mat[i][j] / mat[j][j];
      }
    }
  }

  for (j = n - 1; j >= 0; --j) {
    for (t = 0.0, k = j + 1; k < n; ++k) {
      t += mat[j][k] * x[k];
    }
    x[j] = (mat[j][n] - t) / mat[j][j];
  }
  return x;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int h = n * (n + 1) / 2;

  // build a physical grid to make it easy to compute the neighbors
  vector<vector<int>> grid(n);
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      grid[i].push_back(cur++);
    }
  }

  vector<double> payout(h);
  for (int i = 0; i < h; ++i) cin >> payout[i];
  vector<vector<double>> mat(h, vector<double>(h + 1));
  cur = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      // Expectation of cell k can be described as:
      // E[k] = p0 E[topleft] + p1 E[topright] + p2 E[botleft] +
      //        p3 E[botright] + p4(payout_k)
      // Which can be rearranged as following in the matrix:
      // -E[k] + p0 E[topleft] + p1 E[topright] +
      //           p2 E[botleft] + p3 E[botright] = -p4(payout_k)
      double p0, p1, p2, p3, p4;
      cin >> p0 >> p1 >> p2 >> p3 >> p4;

      // fill in matrix - also check for bounds
      if (j > 0 && i > 0) {
        int topleft = grid[i - 1][j - 1];
        mat[cur][topleft] = p0;
      }
      if (j < i && i > 0) {
        int topright = grid[i - 1][j];
        mat[cur][topright] = p1;
      }
      if (i < n - 1) {
        int botleft = grid[i + 1][j];
        mat[cur][botleft] = p2;
        int botright = grid[i + 1][j + 1];
        mat[cur][botright] = p3;
      }
      mat[cur][cur] = -1;
      mat[cur][h] = -p4 * payout[cur];

      ++cur;
    }
  }

  cout << setprecision(12) << gaussian(mat, h)[0] << endl;

  return 0;
}
