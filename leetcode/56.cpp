// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 56
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
 public:
  vector<Interval> merge(vector<Interval>& intervals) {
    // first: position of event
    // second: 0 for start, 1 for end
    vector<pair<int, int>> events;
    for (Interval x : intervals) {
      events.push_back({x.start, 0});
      events.push_back({x.end, 1});
    }

    // sort the events - note that starts at the same pos end up before the ends
    sort(events.begin(), events.end());

    // now we can just iterate through and check whenever we have no intervals
    // active
    vector<Interval> res;
    int active = 0;  // number of active intervals
    for (const pair<int, int>& e : events) {
      if (e.second == 0) {  // start an interval
        if (active == 0) {
          res.push_back(Interval(e.first, 0));
        }
        ++active;
      } else {  // end an interval
        --active;
        if (active == 0) {
          res.back().end = e.first;
        }
      }
    }

    return res;
  }
};
