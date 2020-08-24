// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) saveprincess
// Title: Bot saves princess
// Link: https://www.hackerrank.com/challenges/saveprincess
// Idea: Find the location of the princess, then print out the moves to get
// there.
// Difficulty: easy
// Tags: implementation
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  string line;
  for (int r = 0; r < n; ++r) {
    cin >> line;
    size_t c = line.find('p');  // Princess position.
    if (c != string::npos) {
      for (int i = 0; i < n / 2; ++i) {
        cout << (r == 0 ? "UP\n" : "DOWN\n");
      }
      for (int i = 0; i < n / 2; ++i) {
        cout << (c == 0 ? "LEFT\n" : "RIGHT\n");
      }
      break;
    }
  }

  return 0;
}
