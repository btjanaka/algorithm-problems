// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10261
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

struct info {
  int val;
  int nid;
  int nleft;
  info() { val = nid = nleft = -1; }
};

int len;
vector<int> cars;
vector<vector<info>> dp;
info f(int id, int left, int right) {
  // printf("%d %d %d\n", id, left, right);
  if (dp[id][left].val != -1) return dp[id][left];

  if (id == cars.size() || (left + cars[id] > len && right + cars[id] > len)) {
    info ret;
    ret.val = 0;
    return ret;
  } else if (left == len && right == len) {
    info ret;
    ret.val = 0;
    return ret;
  } else {
    if (left + cars[id] <= len) {
      info res = f(id + 1, left + cars[id], right);
      ++res.val;
      if (res.val > dp[id][left].val) {
        dp[id][left].val = res.val;
        dp[id][left].nid = id + 1;
        dp[id][left].nleft = left + cars[id];
      }
    }
    if (right + cars[id] <= len) {
      info res = f(id + 1, left, right + cars[id]);
      ++res.val;
      if (res.val > dp[id][left].val) {
        dp[id][left].val = res.val;
        dp[id][left].nid = id + 1;
        dp[id][left].nleft = left;
      }
    }
  }

  return dp[id][left];
}

int main() {
  bool first = true;
  int ca;
  GET(ca);
  while (ca--) {
    // input
    GET(len);
    len *= 100;

    int x;
    cars.clear();
    while (GET(x) && x) {
      cars.push_back(x);
    }

    dp.clear();
    dp = vector<vector<info>>(cars.size() + 1, vector<info>(len + 1, info()));

    // output, including retracing steps
    if (first) {
      first = false;
    } else {
      printf("\n");
    }

    info res = f(0, 0, 0);
    printf("%d\n", res.val);

    int prev_left = 0;
    while (res.nleft != -1) {
      if (res.nleft != prev_left) {
        printf("port\n");
      } else {
        printf("starboard\n");
      }
      prev_left = res.nleft;
      res = dp[res.nid][res.nleft];
    }
  }
  return 0;
}
