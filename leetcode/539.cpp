// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 539
// Title: Minimum Time Difference
// Link: https://leetcode.com/problems/minimum-time-difference/
// Idea: Convert the times to minutes, sort them, and find the min difference.
// The min difference will always be between two adjacent times in the sorted
// list.
// Difficulty: Easy
// Tags:
class Solution {
 public:
  int findMinDifference(vector<string>& timePoints) {
    vector<int> times;
    times.reserve(timePoints.size());
    for (const auto& s : timePoints) {
      int hour, minute;
      sscanf(s.c_str(), "%d:%d", &hour, &minute);
      times.push_back(hour * 60 + minute);
    }

    sort(times.begin(), times.end());

    int mintime = INT_MAX;

    for (int i = 0; i < times.size(); ++i) {
      if (i == times.size() - 1) {
        // Edge case to compare the first time to the last time since
        // clocks wrap around.
        mintime = min(mintime, times[0] - times[i] + 1440);
      } else {
        mintime = min(mintime, times[i + 1] - times[i]);
      }
    }

    return mintime;
  }
};
