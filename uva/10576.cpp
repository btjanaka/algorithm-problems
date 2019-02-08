// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10576
// NOTE: This problem is pretty confusing to understand. I highly recommend
// going to this website http://www.algorithmist.com/index.php/UVa_10576
// and looking through the summary and explanation portions to understand what
// is being asked.
// Also: This problem can definitely be solved iteratively as well, by going
// through all subsets of the 12 months and calculating the reports for each.
// Since it's only 12 months, this is definitely possible.
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORe(i, a, b) for (int i = a; i <= b; ++i)
#define GET(x) scanf("%d", &x)
#define PLN putchar('\n')
#define INF 2147483647
typedef long long ll;
using namespace std;

// Build up solutions by adding on either a surplus or deficit to them.
// * reports is bitset with 1 representing surplus and 0 representing deficit.
// * ultimately return maximum earnings possible
ll backtrack(int month, ll s, ll d, int reports, ll sum5, ll cum_sum) {
  if (month == 12) {
    return cum_sum;
  }

  // Subtract off earnings from 5 months ago
  if (month >= 5) sum5 -= (reports & (1 << (month - 5))) ? s : -d;

  // Calculate with deficit. NOTE: We have to account for sum5 here as well
  // because the first few months may have given a really large sum that one
  // deficit cannot take down.
  sum5 -= d;
  ll add_d = (month >= 4 && sum5 >= 0)
                 ? LONG_MIN
                 : backtrack(month + 1, s, d, reports, sum5, cum_sum - d);

  // Calculate with surplus.
  // Only account for the sum of five months if the month is high
  // enough. If the sum is then positive, avoid this value by making it very
  // low.
  sum5 += s + d;  // sum5 added here because it is used in the next line
  ll add_s = (month >= 4 && sum5 >= 0)
                 ? LONG_MIN
                 : backtrack(month + 1, s, d, reports | (1 << month), sum5,
                             cum_sum + s);

  return max(add_s, add_d);
}

int main() {
  ll s, d;
  while (scanf("%lld %lld", &s, &d) > 0) {
    ll res = backtrack(0, s, d, 0, 0, 0);
    if (res >= 0) {
      printf("%lld\n", res);
    } else {
      printf("Deficit\n");
    }
  }
  return 0;
}
