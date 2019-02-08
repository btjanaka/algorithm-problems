// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10503
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORe(i, a, b) for (int i = a; i <= b; ++i)
#define PAI(arr, len) /*Print array of integers*/ \
  {                                               \
    for (int _i = 0; _i < len; ++_i) {            \
      if (_i != len - 1) {                        \
        printf("%d ", arr[_i]);                   \
      } else {                                    \
        printf("%d", arr[_i]);                    \
      }                                           \
    }                                             \
    putchar('\n');                                \
  }
#define PBS(n, len) /*Print a bitset*/ \
  {                                    \
    for (int _i = 0; _i < len; ++_i) { \
      putchar(n % 2 + '0');            \
      n /= 2;                          \
    }                                  \
    putchar('\n');                     \
  }
#define GET(x) scanf("%d", &x)
#define PLN putchar('\n')
#define INF 2147483647
typedef long long ll;
using namespace std;

bool backtrack(int curr, int right, int n, int count,
               map<int, vector<pair<int, bool>>>& values,
               vector<pair<int, int>>& dominoes, vector<bool>& used) {
  // End case: we have enough dominoes
  if (count == n) {
    return curr == right;
  }

  // False if no domino has this value
  if (values.find(curr) == values.end()) return false;

  // Go through all dominoes with this value in them and try to append
  for (unsigned int i = 0; i < values[curr].size(); ++i) {
    int index = values[curr][i].first;
    bool pos = values[curr][i].second;

    if (used[index]) continue;  // Can't use this domino

    used[index] = true;
    if (pos) {  // Use domino in first if pos is true
      if (backtrack(dominoes[index].first, right, n, count + 1, values,
                    dominoes, used)) {
        return true;
      }
    } else {
      if (backtrack(dominoes[index].second, right, n, count + 1, values,
                    dominoes, used)) {
        return true;
      }
    }
    used[index] = false;
  }
  return false;
}

int main() {
  int n;
  int m;
  int left;
  int right;

  // Map of each value to the list of dominoes it is part of. Each of these
  // dominoes has an int telling its index in the dominoes vector and a bool
  // telling whether it is the first or second value in the domino - false for
  // first, true for second
  map<int, vector<pair<int, bool>>> values;

  // Stores all the dominoes with first and second value
  vector<pair<int, int>> dominoes;

  // Whether each domino has been used
  vector<bool> used;

  while (GET(n) && n != 0) {
    values.clear();
    dominoes.clear();
    used.clear();

    // Inputs
    GET(m);
    scanf("%*d %d", &left);
    scanf("%d %*d", &right);

    int one;
    int two;
    FOR(i, 0, m) {
      scanf("%d %d", &one, &two);
      dominoes.push_back(make_pair(one, two));
      used.push_back(false);

      if (values.find(one) == values.end()) {
        values[one] = {};
      }
      if (values.find(two) == values.end()) {
        values[two] = {};
      }

      values[one].push_back(make_pair(dominoes.size() - 1, false));
      values[two].push_back(make_pair(dominoes.size() - 1, true));
    }

    // Find solution
    if (backtrack(left, right, n, 0, values, dominoes, used)) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
