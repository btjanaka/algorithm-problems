// Author: btjanaka (Bryon Tjanaka)
// Problem: (Hash Code 2019)
// The basic idea in this solution was to view the problem as a huge graph.
// However, it is not feasible to generate the whole graph (and at any rate,
// finding the longest path is an NP hard problem). Hence, the plan was to pick
// a random starting node and then greedily keep picking the "neighboring"
// pictures that would provide the maximal score. This mainly works for
// horizontal pictures; I tried to implement vertical pictures by randomly
// picking another vertical picture when one was reached, but it did not work
// too well.
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

struct data {
  int n;
  vector<vector<string>> id_to_tags;
  unordered_map<string, vector<int>> tags_to_id;
  vector<char> orientation;
  vector<int> verticals;
  data(int n) : n(n), id_to_tags(n), orientation(n) {}
};

data input() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  cin.get();
  data ret(n);

  string s;

  for (int i = 0; i < n; ++i) {
    ret.orientation[i] = cin.get();
    if (ret.orientation[i] == 'V') {
      ret.verticals.push_back(i);
    }
    int m;
    cin >> m;
    for (int j = 0; j < m; ++j) {
      cin >> s;
      ret.id_to_tags[i].push_back(s);
      if (ret.tags_to_id.find(s) == ret.tags_to_id.end()) {
        ret.tags_to_id[s] = {};
      }
      ret.tags_to_id[s].push_back(i);
    }
    cin.get();  // extra newline
  }

  return ret;
}

void print_input(data& in) {
  printf("%d\n", in.n);
  for (char ch : in.orientation) printf("%c\n", ch);
  for (vector<string> x : in.id_to_tags) {
    for (string s : x) {
      printf("%s\n", s.c_str());
    }
  }
  fflush(stdout);
}

vector<int> greedy(data& in) {
  vector<int> res;

  // random start
  random_device device;
  default_random_engine engine(device());
  uniform_int_distribution<int> distr(0, in.n);
  int cur;
  while (true) {
    cur = distr(engine);
    if (in.orientation[cur] == 'H') break;
  }

  vector<bool> visited(in.n, false);
  visited[cur] = true;
  res.push_back(cur);

  // greedy going through nodes - keep choosing one with most neighbors
  int tot_score = 0;
  while (true) {
    unordered_map<int, int> neighbors;
    for (const string& tag : in.id_to_tags[cur]) {
      for (int id : in.tags_to_id[tag]) {
        if (visited[id]) continue;
        if (in.orientation[id] == 'V') continue;
        if (neighbors.find(id) == neighbors.end()) {
          neighbors[id] = 0;
        }
        ++neighbors[id];
      }
    }

    // break when there is nowhere to go :(
    if (neighbors.size() == 0) break;

    // find max neighbor
    int mx_next = 0;
    int mx_score = 0;
    for (const pair<int, int>& x : neighbors) {
      int score = min(x.second, (int)in.id_to_tags[cur].size() - x.second);
      score = min(score, (int)in.id_to_tags[x.first].size() - x.second);
      if (score > mx_score) {
        mx_score = score;
        mx_next = x.first;
      }
    }
    cur = mx_next;
    visited[cur] = true;
    res.push_back(cur);

    // commented out vertical code
    // if (in.orientation[cur] == 'V') {
    //   uniform_int_distribution<int> vdist(0, in.verticals.size());
    //   int nextv;
    //   bool ok = false;
    //   for (int tries = 0; tries < 100; ++tries) {
    //     nextv = vdist(engine);
    //     if (!visited[nextv]) {
    //       ok = true;
    //       break;
    //     }
    //   }
    //   if (ok) {
    //     cur = nextv;
    //     visited[cur] = true;
    //     res.push_back(cur);
    //   } else {
    //     // avoid the vertical if we could not find a match
    //     res.pop_back();
    //   }
    // }
  }

  return res;
}

int main() {
  data in = input();
  vector<int> res = greedy(in);

  int slides = 0;
  for (int i = 0; i < res.size(); ++i) {
    if (in.orientation[res[i]] == 'V') {
      ++i;
      ++slides;
    } else {
      ++slides;
    }
  }
  printf("%d\n", slides);
  for (int i = 0; i < res.size(); ++i) {
    if (in.orientation[res[i]] == 'V') {
      printf("%d %d\n", res[i], res[i + 1]);
      ++i;
    } else {
      printf("%d\n", res[i]);
    }
  }

  return 0;
}
