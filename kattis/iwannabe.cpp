// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) iwannabe
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int n, k;
  GET(n);
  GET(k);
  vector<unsigned int> pokemons[1010];
  for (unsigned int i = 0; i < n; ++i) {
    unsigned int a, d, h;
    scanf("%u %u %u", &a, &d, &h);
    pokemons[i] = {i, a, d, h};
  }
  unordered_set<int> selected;
  for (int i = 1; i < 4; ++i) {
    sort(pokemons, pokemons + n,
         [&](const vector<unsigned int>& a, const vector<unsigned int>& b) {
           return a[i] > b[i];
         });
    for (int j = 0; j < k; ++j) {
      selected.insert(pokemons[j][0]);
    }
  }
  printf("%lu\n", selected.size());
  return 0;
}
