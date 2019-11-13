// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) cut-the-tree
// Title: Cut the Tree
// Link: https://www.hackerrank.com/challenges/cut-the-tree/problem
// Idea: Use DFS to traverse the tree and calculate the total value of the
// portion of a tree below each node. We can then calculate the difference we
// would get if we cut that edge.
// Difficulty: medium
// Tags: graph, dfs
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;
struct Node {
  int neighbor;
  Node* next;
};

int findBestCut(Node* graph[], int value[], int n) {
  int total_value = 0;
  for (int i = 0; i < n; ++i) {
    total_value += value[i];
  }

  // Use iterative DFS to find the smallest difference between the cut nodes and
  // the remaining nodes.
  int smallest_diff = total_value;
  int cumsum[n];  // sum of all nodes below and including each node i
  for (int i = 0; i < n; ++i) cumsum[i] = -1;
  int stack[n];
  int stack_ptr = 0;
  stack[0] = 0;
  bool visited[n];
  memset(visited, false, sizeof(visited));
  while (stack_ptr != -1) {
    int u = stack[stack_ptr--];

    if (visited[u]) {
      // If visited already, we can now iterate through and count up
      // the value of this tree.
      cumsum[u] = value[u];
      for (Node* itr = graph[u]; itr != NULL; itr = itr->next) {
        int v = itr->neighbor;
        if (cumsum[v] != -1) cumsum[u] += cumsum[v];
      }
      int remaining = total_value - cumsum[u];
      int diff = remaining - cumsum[u];
      if (diff < 0) diff = -diff;
      if (diff < smallest_diff) smallest_diff = diff;
    } else {
      // Otherwise, we keep u on the stack and push its children for
      // calculation.
      visited[u] = true;
      stack[++stack_ptr] = u;
      for (Node* itr = graph[u]; itr != NULL; itr = itr->next) {
        if (visited[itr->neighbor]) continue;
        stack[++stack_ptr] = itr->neighbor;
      }
    }
  }

  // debugging: Prints out the sums.
  // printf("total_value: %d\n", total_value);
  // for(int i = 0; i < n; ++i) {
  //     printf("%d: %d %d\n", i + 1, value[i], cumsum[i]);
  // }

  return smallest_diff;
}

int main() {
  int n;
  scanf("%d", &n);
  int value[n];
  for (int i = 0; i < n; ++i) scanf("%d", value + i);

  Node* graph[n];  // adjacency list - each element is singly linked list of
                   // neighbors
  memset(graph, false, sizeof(graph));
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u;
    --v;

    Node* oldu = graph[u];
    graph[u] = malloc(sizeof(Node));
    graph[u]->neighbor = v;
    graph[u]->next = oldu;

    Node* oldv = graph[v];
    graph[v] = malloc(sizeof(Node));
    graph[v]->neighbor = u;
    graph[v]->next = oldv;
  }

  printf("%d\n", findBestCut(graph, value, n));

  return 0;
}
