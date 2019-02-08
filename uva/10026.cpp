// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10026
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORe(i, a, b) for (int i = a; i <= b; ++i)
#define PAI(arr, len) /*Print array of integers*/ \
  {                                               \
    for (int _i = 0; _i < len; ++_i) {            \
      if (_i != len - 1) {                        \
        printf("%d ", arr[_i]);                   \
      } else {                                    \
        printf("%d", arr[_i]);                    \
      }                                           \
    }                                             \
    putchar('\n');                                \
  }
#define PBS(n, len) /*Print a bitset*/ \
  {                                    \
    for (int _i = 0; _i < len; ++_i) { \
      putchar(n % 2 + '0');            \
      n /= 2;                          \
    }                                  \
    putchar('\n');                     \
  }
#define GET(x) scanf("%d", &x)
#define PLN putchar('\n')
#define INF 2147483647
typedef long long ll;
using namespace std;

// Given two jobs, job 1 with fine s1 and days t1, and job 2 with fine s2 and
// days t2, we can compare which one we want to do by looking at s1t2 and s2t1.
// s1t2 is the fine accumulated if we do job 2 first, since we have to pay fine
// s1 for t2 days. s2t1 is the fine accumulated if we do job 1 first, since we
// have to pay fine s2 for t1 days. If s1t2 > s2t1, we will want to do job 1
// first, since that will accumulate the lesser fine (s2t1). We can rearrange
// the equation to be s1/t1 > s2/t2, and we can now use the cost per day ratios
// of each job as a way to compare them with ease. If a job has a smaller s/t
// per day ratio, it should be done last because of the inequality above.
//
// i.e. s1/t1 > s2/t2 --> s1t2 > s2t1 --> do the job with s1 and t1 (job 1)
// first

// first: day per cost ratio
// second: id
pair<float, int> jobs[1010];

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    int n;
    GET(n);
    // Use a days per cost ratio (i.e. inverted) to allow us to use the default
    // pair comparator.
    FOR(i, 0, n) {
      float t, s;
      scanf("%f %f", &t, &s);
      jobs[i].first = t / s;
      jobs[i].second = i + 1;
    }
    sort(jobs, jobs + n);

    // Print results
    printf("%d", jobs[0].second);
    FOR(i, 1, n) { printf(" %d", jobs[i].second); }
    PLN;
    if (ca) PLN;
  }
  return 0;
}
