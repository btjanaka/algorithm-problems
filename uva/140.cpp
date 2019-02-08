// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 140
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORe(i, a, b) for (int i = a; i <= b; ++i)
#define PAI(arr, len) /*Print array of integers*/ \
  {                                               \
    for (int _i = 0; _i < len; ++_i) {            \
      if (_i != len - 1) {                        \
        printf("%d ", arr[_i]);                   \
      } else {                                    \
        printf("%d\n", arr[_i]);                  \
      }                                           \
    }                                             \
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

// Each entry is a node.
// Each node is a bitset telling which nodes it is connected to.
// 'A' is bit 0, 'Z' is bit 25.
int graph[26];

int main() {
  char buf[300];
  while (scanf("%s", buf) && buf[0] != '#') {
    memset(graph, 0, sizeof(graph));
    // Input
    char* token = strtok(buf, ";");
    while (token != NULL) {
      int node1 = token[0] - 'A';
      for (int i = 2; token[i] != 0; ++i) {
        int node2 = token[i] - 'A';
        graph[node1] |= 1 << node2;  // Add nodes to the bitset
        graph[node2] |= 1 << node1;
      }
      token = strtok(NULL, ";");
    }

    // Initialize the array that will be used to find all permutations of
    // orders.
    int ordering[8];
    int num_nodes = 0;
    FOR(i, 0, 26) {
      if (graph[i]) {
        ordering[num_nodes++] = i;
      }
    }

    // Ordering Bandwidth calculation: Find max bandwidth, then compare to
    // current ordering bandwidth to get min.
    int res[8];
    int min_ordering_bandwidth = INF;
    do {
      int max_bandwidth = 0;
      FOR(i, 0, num_nodes) {
        FOR(j, i + 1, num_nodes) {
          // Check if the two nodes are connected
          if (graph[ordering[i]] & (1 << ordering[j])) {
            max_bandwidth = max(max_bandwidth, j - i);
          }
        }
      }
      if (max_bandwidth < min_ordering_bandwidth) {
        min_ordering_bandwidth = max_bandwidth;
        memcpy(res, ordering, sizeof(int) * num_nodes);
      }
    } while (next_permutation(ordering, ordering + num_nodes));

    // Output
    FOR(i, 0, num_nodes) { printf("%c ", res[i] + 'A'); }
    printf("-> %d\n", min_ordering_bandwidth);
  }
  return 0;
}
