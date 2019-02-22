class MyHashMap {
 public:
  /** Initialize your data structure here. */
  MyHashMap() : buf(new node*[10]), size(10) {
    for (int i = 0; i < size; ++i) {
      buf[i] = new node({0, 0}, nullptr);
    }
  }

  /** value will always be non-negative. */
  void put(int key, int value) {
    int index = key % size;
    node* cur = buf[index];
    while (true) {
      if (cur->next) {
        if (cur->next->info.first == key) {
          cur->next->info.second = value;
          break;
        } else {
          cur = cur->next;
        }
      } else {
        cur->next = new node({key, value}, nullptr);
        ++cur_size;
        break;
      }
    }
    if ((double)cur_size / (double)size > load_factor) {
      resize();
    }
  }

  /** Returns the value to which the specified key is mapped, or -1 if this map
   * contains no mapping for the key */
  int get(int key) {
    int index = key % size;
    for (node* cur = buf[index]->next; cur; cur = cur->next) {
      if (cur->info.first == key) return cur->info.second;
    }
    return -1;
  }

  /** Removes the mapping of the specified value key if this map contains a
   * mapping for the key */
  void remove(int key) {
    int index = key % size;
    printf("%d\n", key);
    for (node* cur = buf[index]; cur->next; cur = cur->next) {
      if (cur->next->info.first == key) {
        cur->next = cur->next->next;
        break;
      }
    }
  }

 private:
  struct node {
    pair<int, int> info;
    node* next;
    node(const pair<int, int>& info, node* next) : info(info), next(next) {}
  };

  node** buf;
  int size;
  int cur_size;
  double load_factor = 0.75;

  void resize() {
    node** tmp = buf;
    size *= 2;
    buf = new node*[size];
    for (int i = 0; i < size; ++i) {
      buf[i] = new node({0, 0}, nullptr);
    }
    for (int i = 0; i < size / 2; ++i) {
      for (node* cur = tmp[i]->next; cur; cur = cur->next) {
        this->put(cur->info.first, cur->info.second);
      }
    }
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
