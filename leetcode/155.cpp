// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 155
// Title: Min Stack
// Link: https://leetcode.com/problems/min-stack/
// Idea: Use an STL stack as the basis, but in the stack, store pairs where the
// first element is the integer input and the second element is the minimum of
// the remaining elements in the stack. By caching the minimum element, we don't
// have to search through the rest of the stack whenever we pop from it.
// Difficulty: easy
// Tags: stack
class MinStack {
 public:
  /** initialize your data structure here. */
  MinStack() : s() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
  }

  void push(int x) {
    int newmn;
    if (s.empty()) {
      newmn = x;
    } else {
      newmn = min(mn, x);
    }
    // Push the old minimum as well as x.
    s.push({x, mn});
    mn = newmn;
  }

  void pop() {
    mn = s.top().second;
    s.pop();
  }

  int top() { return s.top().first; }

  int getMin() { return mn; }

 private:
  // {x, min}
  stack<pair<int, int>> s;
  int mn;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
