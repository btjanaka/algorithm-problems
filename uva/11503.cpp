// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11503
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

struct UnionFind {
  unordered_map<string, string> p;
  unordered_map<string, int> rank, size;
  UnionFind() : size(), p() {}
  void add(const string& a, const string& b) {
    if (p.find(a) == p.end()) {
      p[a] = a;
      size[a] = 1;
      rank[a] = 0;
    }
    if (p.find(b) == p.end()) {
      p[b] = b;
      size[b] = 1;
      rank[b] = 0;
    }
    unionSet(a, b);
  }
  string findSet(const string& a) {
    return a == p[a] ? a : (p[a] = findSet(p[a]));
  }
  bool isSameSet(const string& a, const string& b) {
    return findSet(a) == findSet(b);
  }
  void unionSet(const string& a, const string& b) {
    if (!isSameSet(a, b)) {
      string x = findSet(a), y = findSet(b);
      if (rank[x] < rank[y]) {
        p[x] = y;
        size[y] += size[x];
      } else {
        p[y] = x;
        size[x] += size[y];
        if (rank[x] == rank[y]) {
          ++rank[x];
        }
      }
    }
  }
  int sz(const string& a) { return size[findSet(a)]; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int ca;
  cin >> ca;
  while (ca--) {
    int f;
    cin >> f;
    UnionFind uf;
    string a, b;
    while (f--) {
      cin >> a >> b;
      uf.add(a, b);
      cout << uf.sz(a) << endl;
    }
  }
  return 0;
}
