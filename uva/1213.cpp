// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 1213
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int p;
int primes[200];

void generate_primes() {
  bool nums[1121];
  p = 0;
  memset(nums, true, sizeof(nums));
  nums[0] = nums[1] = false;
  for (int i = 2; i <= 1120; ++i) {
    if (nums[i]) {
      primes[p++] = i;
      for (int j = i + i; j <= 1120; j += i) {
        nums[j] = false;
      }
    }
  }
}

int n, k;
int dp[200][1150][15];
int f(int id, int amt, int used) {
  if (dp[id][amt][used] >= 0) return dp[id][amt][used];

  if (id == p) {
    return amt == n && used == k;
  } else if (amt == n) {
    return used == k;
  } else if (used == k) {
    return amt == n;
  } else {
    dp[id][amt][used] = f(id + 1, amt, used);
    if (amt + primes[id] <= n) {
      dp[id][amt][used] += f(id + 1, amt + primes[id], used + 1);
    } else {
      return 0;  // shortcut because no future primes will work since they are
                 // sorted
    }
  }

  return dp[id][amt][used];
}

int main() {
  generate_primes();
  while (GET(n) && GET(k) && (n || k)) {
    memset(dp, -1, sizeof(dp));
    printf("%d\n", f(0, 0, 0));
  }
  return 0;
}
