// Author: btjanaka (Bryon Tjanaka)
// Problem: (Google Code Jam) Cryptopangrams
// Note: does not work on larger input
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

vector<int> primes;
unordered_map<int, ii>
    products;  // mapping of products to their comps - note comps are sorted
void calc_primes() {
  bool is_prime[10001];
  memset(is_prime, true, sizeof(is_prime));
  for (int i = 2; i <= 10000; ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = i + i; j <= 10000; j += i) {
        is_prime[j] = false;
      }
    }
  }
  for (int i = 0; i < primes.size(); ++i) {
    for (int j = i; j < primes.size(); ++j) {
      products[primes[i] * primes[j]] = {min(primes[i], primes[j]),
                                         max(primes[i], primes[j])};
    }
  }
}

int main() {
  calc_primes();
  int ca;
  GET(ca);
  for (int caa = 1; caa <= ca; ++caa) {
    int n, L;
    GET(n);
    GET(L);
    vector<int> msg, p_msg;
    set<int> primes_used;
    for (int i = 0; i < L; ++i) {
      int x;
      GET(x);
      msg.push_back(x);
      primes_used.insert(products[x].first);
      primes_used.insert(products[x].second);
      p_msg.push_back(products[x].first);
      p_msg.push_back(products[x].second);
    }

    unordered_map<int, char> chars;
    char cur = 'A';
    for (int p : primes_used) {
      chars[p] = cur++;
    }

    // find first index where the two are not equal
    int start = 0;
    // for (int i = 0; i < 2 * L - 2; i += 2) {
    //   if (p_msg[i] != p_msg[i + 2] || p_msg[i + 1] != p_msg[i + 3]) {
    //     start = i;
    //     break;
    //   }
    // }
    for (int i = 0; i < L - 1; ++i) {
      if (msg[i] != msg[i + 1]) {
        start = i * 2;
        break;
      }
    }

    // start aligning
    for (int i = start; i < 2 * L - 2; i += 2) {
      if (p_msg[i + 1] != p_msg[i + 2]) {
        if (i == start) {
          if (p_msg[i] == p_msg[i + 2]) {
            swap(p_msg[i], p_msg[i + 1]);
          } else if (p_msg[i] == p_msg[i + 3]) {
            // yes, it's possible to swap both
            swap(p_msg[i], p_msg[i + 1]);
            swap(p_msg[i + 2], p_msg[i + 3]);
          } else {
            swap(p_msg[i + 2], p_msg[i + 3]);
          }
        } else {
          swap(p_msg[i + 2], p_msg[i + 3]);
        }
      }
    }

    // align first part
    for (int i = start; i >= 2; i -= 2) {
      if (p_msg[i] != p_msg[i - 1]) {
        swap(p_msg[i - 1], p_msg[i - 2]);
      }
    }

    // build result and output
    string res;
    for (int i = 0; i < 2 * L; i += 2) {
      res.push_back(chars[p_msg[i]]);
    }
    res.push_back(chars[p_msg.back()]);
    printf("Case #%d: %s\n", caa, res.c_str());
  }
  return 0;
}
