// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 900
class RLEIterator {
 public:
  vector<int> data;
  int curr_count_tgt;
  int curr_count;
  int curr_val;
  int curr_ind;
  bool first;

  RLEIterator(vector<int> A) {
    data = A;
    curr_count_tgt = 0;
    curr_count = 0;
    curr_val = 0;
    curr_ind = 0;
    first = true;
  }

  int single() {
    if (curr_ind == data.size()) return -1;

    // Find new value
    if (curr_count == curr_count_tgt) {
      if (first) {
        first = false;
      } else {
        curr_ind += 2;
      }
      while (curr_ind < data.size() && data[curr_ind] == 0) curr_ind += 2;
      if (curr_ind == data.size()) return -1;
      curr_count = 1;
      curr_count_tgt = data[curr_ind];
      curr_val = data[curr_ind + 1];
      return curr_val;
    }

    // Return current value
    curr_count += 1;
    return curr_val;
  }

  int next(int n) {
    int i = n;
    while (i != 1) {
      int inc = min(i - 2, curr_count_tgt - curr_count);
      curr_count += inc;
      i -= inc;
      single();
      --i;
    }
    printf("%d %d %d %d\n", curr_count, curr_count_tgt, curr_val, curr_ind);
    return single();
  }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */
