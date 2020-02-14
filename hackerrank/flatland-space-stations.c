// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) flatland-space-stations
// Title: Flatland Space Stations
// Link: https://www.hackerrank.com/challenges/flatland-space-stations/problem
// Idea: Sort the stations. Between every pair of stations, the max distance
// to a station is half of the distance between the stations. Make sure to check
// the first and last city as well -- these cities will not lie between a pair
// of space stations.
// Difficulty: easy
// Tags: array, implementation
#include <stdio.h>
#include <stdlib.h>

int space_stations[100100];

inline int max(int a, int b) { return a > b ? a : b; }

int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  // Input the space stations and sort them.
  for (int i = 0; i < m; ++i) scanf("%d", &space_stations[i]);
  qsort(space_stations, m, sizeof(int), compare);

  // Initialize with distance from first station to city 0.
  int mx_dist = space_stations[0];

  // Check distance between every pair of cities.
  for (int i = 1; i < m; ++i) {
    mx_dist = max(mx_dist, (space_stations[i] - space_stations[i - 1]) / 2);
  }

  // Distance from last station to last city.
  mx_dist = max(mx_dist, n - 1 - space_stations[m - 1]);

  printf("%d", mx_dist);

  return 0;
}
