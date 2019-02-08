// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10684
#include<bits/stdc++.h>
using namespace std;

int sums[10010];

int main() {
  int n;
  while(scanf("%d", &n) && n > 0) {
    // Input the numbers and calculate the sums.
    // Each entry in the array sums is the sum of that number
    // and all the numbers before it.
    for(int i = 0; i < n; ++i) {
      scanf("%d", &sums[i]);
      if(i != 0)
        sums[i] = sums[i] + sums[i-1];
    }

    // Calculate the maximum difference to get the maximum streak.
    int mx = sums[0];
    for(int i = 0; i < n; ++i) {
      for(int j = i+1; j < n; ++j) {
        int val = sums[j] - sums[i];
        if(val > mx) mx = val;
      }
    }

    // Print results.
    if(mx > 0) printf("The maximum winning streak is %d.\n", mx);
    else printf("Losing streak.\n");
  }
  return 0;
}
