// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11402
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

// key here is to optimize for when we know a range has all 1's or all 0's -
// we can modify higher ranges instead of having to go all the way down to
// individual 1's and 0's - but this also means the lower levels don't know
// about the higher range, so if we have to modify a lower range we have to
// update it with the higher range value first (see update_range)
struct SegmentTree {
  vector<int> v, st;
  int n;

  int left(int p) { return p << 1; }
  int right(int p) { return (p << 1) + 1; }

  void build(int p, int l, int r) {
    if (l == r) {
      st[p] = v[l];
    } else {
      build(left(p), l, (l + r) / 2);
      build(right(p), (l + r) / 2 + 1, r);
      st[p] = st[left(p)] + st[right(p)];
    }
  }

  int rsq(int p, int l, int r, int i, int j) {
    if (j == r && i == l) {
      return st[p];
    }

    // optimize for when we know the whole range has 1's or 0's
    if (j <= r && i >= l) {
      if (st[p] == r - l + 1) {
        return j - i + 1;
      }
      if (st[p] == 0) {
        return 0;
      }
    }

    int lsum = 0, rsum = 0;
    if (i <= (l + r) / 2) {
      lsum = rsq(left(p), l, (l + r) / 2, i, min(j, (l + r) / 2));
    }
    if (j >= (l + r) / 2 + 1) {
      rsum = rsq(right(p), (l + r) / 2 + 1, r, max(i, (l + r) / 2 + 1), j);
    }

    return lsum + rsum;
  }
  int rsq(int i, int j) { return rsq(1, 0, n - 1, i, j); }

  void update_range(int p, int l, int r, int i, int j, int val) {
    if (j == r && i == l) {
      // optimize for when we know the whole range has 1's or 0's
      if (val == 1) {
        st[p] = r - l + 1;
        return;
      } else if (val == 0) {
        st[p] = 0;
        return;
      } else {
        // invert, but only if all the pirates in this range are equal
        if (st[p] == r - l + 1) {
          st[p] = 0;
          return;
        }
        if (st[p] == 0) {
          st[p] = r - l + 1;
          return;
        }
      }
    }

    // update left and right vals
    if (st[p] == r - l + 1) {
      st[left(p)] = (l + r) / 2 - l + 1;
      st[right(p)] = r - ((l + r) / 2 + 1) + 1;
    } else if (st[p] == 0) {
      st[left(p)] = 0;
      st[right(p)] = 0;
    }

    if (i <= (l + r) / 2) {
      update_range(left(p), l, (l + r) / 2, i, min(j, (l + r) / 2), val);
    }
    if (j >= (l + r) / 2 + 1) {
      update_range(right(p), (l + r) / 2 + 1, r, max(i, (l + r) / 2 + 1), j,
                   val);
    }

    st[p] = st[left(p)] + st[right(p)];
  }
  void update_range(int i, int j, int val) {
    update_range(1, 0, n - 1, i, j, val);
  }

  SegmentTree(const vector<int>& _v) {
    v = _v;
    n = v.size();
    st.assign(4 * n, 0);
    build(1, 0, n - 1);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int ca;
  cin >> ca;
  for (int caa = 1; caa <= ca; ++caa) {
    printf("Case %d:\n", caa);

    int m;
    cin >> m;
    string p, s;
    while (m--) {
      int t;
      cin >> t;
      cin >> s;
      while (t--) p += s;
    }
    vector<int> pirates;
    for (char ch : p) pirates.push_back(ch - '0');
    SegmentTree st(pirates);

    int q;
    int gq = 1;
    cin >> q;
    getline(cin, s);
    while (q--) {
      getline(cin, s);
      char ch;
      int a, b;
      sscanf(s.c_str(), "%c %d %d", &ch, &a, &b);
      switch (ch) {
        case 'F':
          st.update_range(a, b, 1);
          break;
        case 'E':
          st.update_range(a, b, 0);
          break;
        case 'I':
          st.update_range(a, b, -1);
          break;
        case 'S':
          printf("Q%d: %d\n", gq++, st.rsq(a, b));
      }
    }
  }
  return 0;
}
