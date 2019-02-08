// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10141
#include <bits/stdc++.h>
using namespace std;

int main() {
  int reqs;
  int proposal_index;

  char proposal_names[10000][100];  // All proposal_count
  float proposal_prices[10000];
  int proposal_reqs[10000];
  int proposal_count;

  char top_proposal_names[10000][100];  // All proposal_names with the most reqs
  float top_proposal_prices[10000];
  int top_proposal_count;

  char best_proposal[100];  // The best proposal

  char dummy[100];

  scanf("%d %d\n", &reqs, &proposal_count);

  for (proposal_index = 1; reqs > 0 && proposal_count > 0; ++proposal_index) {
    // Throw away all the requirement names - unnecessary
    for (int i = 0; i < reqs; ++i) {
      fgets(dummy, 100, stdin);
    }

    // Record all proposal names, prices, and number of reqs satisfied
    for (int i = 0; i < proposal_count; ++i) {
      fgets(proposal_names[i], 100, stdin);
      *strrchr(proposal_names[i], '\n') = 0;
      scanf("%f %d\n", &proposal_prices[i], &proposal_reqs[i]);
      // Throw away all reqs again
      for (int j = 0; j < proposal_reqs[i]; ++j) {
        fgets(dummy, 100, stdin);
      }
    }

    // Find the set of top proposals
    top_proposal_count = 0;
    int max_reqs = 0;
    for (int i = 0; i < proposal_count; ++i)
      if (proposal_reqs[i] > max_reqs) max_reqs = proposal_reqs[i];
    for (int i = 0; i < proposal_count; ++i) {
      if (proposal_reqs[i] == max_reqs) {
        strcpy(top_proposal_names[top_proposal_count], proposal_names[i]);
        top_proposal_prices[top_proposal_count] = proposal_prices[i];
        ++top_proposal_count;
      }
      // printf("%s %f\n", top_proposal_names[i], proposal_prices[i]);
    }

    // Find the best proposal - pay attention to the order here - we have
    // to go reverse because if two proposals have the same requirements
    // and price, we have to give the name of the one that appeared FIRST
    // in the input.
    float min_price = top_proposal_prices[top_proposal_count - 1];
    for (int i = top_proposal_count - 1; i >= 0; --i) {
      if (top_proposal_prices[i] <= min_price) {
        min_price = top_proposal_prices[i];
        strcpy(best_proposal, top_proposal_names[i]);
      }
    }

    // Print result
    printf("RFP #%d\n%s\n", proposal_index, best_proposal);
    // Get next data set
    scanf("%d %d\n", &reqs, &proposal_count);
    // Print a blank line if necessary
    if (reqs > 0 && proposal_count > 0) putchar('\n');
  }

  return 0;
}
