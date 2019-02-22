// Skip list

class MedianFinder {
 public:
  /** initialize your data structure here. */
  MedianFinder()
      : device_(),
        engine_(device_()),
        choice_(0, 1),
        size_(0u),
        heads_(1, new node()),
        median_(heads_[0]) {}

  void addNum(int num) {
    insert(num, heads_.size() - 1, heads_.back());
    ++size_;
    if (median_ == heads_[0]) {
      median_ = heads_[0]->next;
    } else {
      if (size_ % 2 == 1) {
        if (num >= median_->val) {
          median_ = median_->next;
        } else {
          // do nothing
        }
      } else {
        if (num >= median_->val) {
          // do nothing
        } else {
          median_ = median_->prev;
        }
      }
    }
  }

  double findMedian() {
    /*printf("BEGIN\n");
    for(int i = heads_.size() - 1; i >= 0; --i) {
        for(node* cur = heads_[i]->next; cur != nullptr; cur = cur->next) {
            printf("%d ", cur->val);
            if(i != 0) printf("(%dv) ", cur->below->val);
        }
        printf("\n");
    }
    printf("END\n");

    printf("%d\n", median_->val);
    */

    if (size_ == 0) {
      return 0.0;
    } else if (size_ % 2 == 0) {
      return double(median_->val + median_->next->val) / 2.0;
    } else {
      return median_->val;
    }
  }

 private:
  struct node {
    int val;
    node* prev;
    node* next;
    node* below;
    node() : val(0), prev(nullptr), next(nullptr), below(nullptr) {}
    node(int _val, node* _prev, node* _next, node* _below)
        : val(_val), prev(_prev), next(_next), below(_below) {}
  };

  // randomness for skip list
  random_device device_;
  default_random_engine engine_;
  uniform_int_distribution<int> choice_;

  unsigned int size_;
  vector<node*> heads_;
  node* median_;

  node* insert(int num, int lvl, node* cur) {
    // Advance while less than or equal to next - thuse we always add duplicates
    // to the end of the duplicates
    for (; cur->next && cur->next->val <= num; cur = cur->next)
      ;
    node* ret;

    // Always add on bottom
    if (lvl == 0) {
      node* newnode = new node(num, cur, cur->next, nullptr);
      if (cur->next) cur->next->prev = newnode;
      cur->next = newnode;
      ret = cur->next;
    } else {
      // Add onto this level only if the choice works and the below levels
      // worked too
      node* below = insert(num, lvl - 1, cur->below);
      if (choice_(engine_) && below) {
        node* newnode = new node(num, cur, cur->next, below);
        if (cur->next) cur->next->prev = newnode;
        cur->next = newnode;
        ret = cur->next;
      } else {
        ret = nullptr;  // prevents higher levels
      }
    }

    // Possibly add on more levels above
    if (lvl == heads_.size() - 1 && ret && choice_(engine_)) {
      heads_.push_back(new node(num, nullptr, nullptr, heads_.back()));
      heads_.back()->next = new node(num, heads_.back(), nullptr, ret);
    }

    return ret;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
