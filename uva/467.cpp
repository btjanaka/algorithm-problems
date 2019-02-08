// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 467
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string buf;
  for (int ca = 1; getline(cin, buf); ++ca) {
    stringstream ss(buf);
    vector<int> nums;
    int x;
    while (ss >> x) nums.push_back(x);

    int t = 0;
    vector<char> state(nums.size(), 'G');
    bool first = true;
    bool ok = false;
    while (t <= 3600) {
      bool all_green =
          all_of(state.begin(), state.end(), [](char c) { return c == 'G'; });
      if (all_green && !first) {
        ok = true;
        break;
      }
      if (!all_green && first) first = false;

      ++t;

      // update
      for (int i = 0; i < state.size(); ++i) {
        if (t / nums[i] % 2 == 1) {
          // red on odd numbered cycles
          state[i] = 'R';
        } else {
          // green or yellow depending on time left
          if (nums[i] - t % nums[i] > 5) {
            state[i] = 'G';
          } else {
            state[i] = 'Y';
          }
        }
      }
    }

    printf("Set %d ", ca);
    if (ok) {
      printf(
          "synchs again at %d minute(s) and %d second(s) after all turning "
          "green.\n",
          t / 60, t % 60);
    } else {
      printf("is unable to synch after one hour.\n");
    }
  }
  return 0;
}
