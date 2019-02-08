// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11235
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

// see http://niceproblems.blogspot.com/2012/05/uva-11235-frequent-values.html
// for explanation - this one's tough... :(

struct SegmentTree {
  vector<int> v, freq, start;
  vector<int> st;
  int n;

  int left(int p) { return p << 1; }
  int right(int p) { return (p << 1) + 1; }

  void build(int p, int l, int r) {
    if (r == l) {
      st[p] = freq[l];
    } else {
      build(left(p), l, (l + r) / 2);
      build(right(p), (l + r) / 2 + 1, r);
      st[p] = max(st[left(p)], st[right(p)]);
    }
  }

  int rmq(int p, int l, int r, int i, int j) {
    if (i > r || j < l) return -1;
    if (l >= i && r <= j) return st[p];

    int lmx = rmq(left(p), l, (l + r) / 2, i, j);
    int rmx = rmq(right(p), (l + r) / 2 + 1, r, i, j);

    if (rmx == -1) return lmx;
    if (lmx == -1) return rmx;
    return max(lmx, rmx);
  }
  int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }

  SegmentTree(const vector<int>& _v) {
    v = _v;
    n = v.size();
    freq.assign(n, 0);
    start.assign(n, 0);

    // make frequencies and starts
    int last = 0;
    for (int i = 0; i < n; ++i) {
      if (v[i] != v[last]) {
        for (int j = last; j < i; ++j) {
          freq[j] = i - last;
          start[j] = last;
        }
        last = i;
      }
    }
    for (int j = last; j < n; ++j) {
      freq[j] = n - last;
      start[j] = last;
    }

    st.assign(4 * n, 0);
    build(1, 0, n - 1);
  }
};

int main() {
  int n, q;
  while (GET(n) && n) {
    GET(q);
    vector<int> v;
    int x;
    for (int i = 0; i < n; ++i) {
      int x;
      GET(x);
      v.push_back(x);
    }

    SegmentTree st(v);

    int i, j;
    for (int k = 0; k < q; ++k) {
      GET(i);
      GET(j);
      --i;
      --j;
      if (v[j] == v[i]) {
        printf("%d\n", j - i + 1);
      } else {
        int cnt1 = st.freq[i] - i + st.start[i];
        int cnt2 = j - st.start[j] + 1;
        int cnt3 = 0;
        int b = st.start[i] + st.freq[i], e = st.start[j] - 1;
        if (b <= e) cnt3 = st.rmq(b, e);
        printf("%d\n", max(max(cnt1, cnt2), cnt3));
      }
    }
  }
  return 0;
}
