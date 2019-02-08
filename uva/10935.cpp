// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10935
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

// discarded, remaining
pair<vector<int>, int> cards[51];

void precalculate() {
  for (int c = 1; c <= 50; ++c) {
    queue<int> nums;
    for (int i = 1; i <= c; ++i) nums.push(i);
    while (nums.size() != 1) {
      cards[c].first.push_back(nums.front());
      nums.pop();
      nums.push(nums.front());
      nums.pop();
    }
    cards[c].second = nums.front();
  }
}

int main() {
  precalculate();
  int n;
  while (GET(n) && n) {
    printf("Discarded cards:");
    for (int i = 0; i < cards[n].first.size(); ++i) {
      printf(" %d%c", cards[n].first[i],
             i == cards[n].first.size() - 1 ? '\n' : ',');
    }
    if (cards[n].first.size() == 0) putchar('\n');
    printf("Remaining card: %d\n", cards[n].second);
  }
  return 0;
}
