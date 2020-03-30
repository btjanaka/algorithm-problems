// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) cloudy-day
// Title: Cloudy Day
// Link: https://www.hackerrank.com/challenges/cloudy-day/problem
// Idea: Think of everything in terms of "events" -- there are events for
// encountering a city, beginning a cloud, and ending a cloud. If we order these
// events by their position, we can iterate through them in order while keeping
// track of what clouds are active, and we can see which cloud covers the most
// cities on its own.
// Difficulty: medium
// Tags: array, implementation
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

// events that happen along the line:
struct event {
  // C - city
  // B - cloud begins
  // E - cloud ends
  char type;

  int id;  // index into the array where the event originates
  int pos;

  event(char type, int id, int pos) : type(type), id(id), pos(pos) {}

  bool operator<(const event& rhs) {
    // sort first by pos
    if (pos != rhs.pos) return pos < rhs.pos;

    // if this event is a city and the other is a cloud end, the city should
    // come first
    if (type == 'C' && rhs.type == 'E') return true;

    // if this event is a cloud begin and the other is a city, the cloud begin
    // should come first
    if (type == 'B' && rhs.type == 'C') return true;

    return false;
  }
};

int main() {
  int n, m;
  while (GET(n) > 0) {
    // input
    vector<ii> cities(n);  // population, position
    for (int i = 0; i < n; ++i) GET(cities[i].first);
    for (int i = 0; i < n; ++i) GET(cities[i].second);
    GET(m);
    vector<ii> clouds(m);  // position, radius
    for (int i = 0; i < m; ++i) GET(clouds[i].first);
    for (int i = 0; i < m; ++i) GET(clouds[i].second);

    // events that happen along the line
    vector<event> events;
    for (int i = 0; i < n; ++i) {
      events.push_back(event('C', i, cities[i].second));
    }
    for (int i = 0; i < m; ++i) {
      events.push_back(event('B', i, clouds[i].first - clouds[i].second));
      events.push_back(event('E', i, clouds[i].first + clouds[i].second));
    }
    sort(events.begin(), events.end());  // see event struct for how this sorts

    // analyze events - have to use long long for summing up population
    // due to size of pop
    ll already_sunny = 0;           // towns that are always sunny
    unordered_set<int> cur_clouds;  // current clouds
    vector<ll> gain(m, 0);          // how many more get sunny for each cloud
    for (event e : events) {
      switch (e.type) {
        case 'B':
          cur_clouds.insert(e.id);
          break;
        case 'E':
          cur_clouds.erase(e.id);
          break;
        case 'C':
          int pop = cities[e.id].first;
          if (cur_clouds.empty()) {
            already_sunny += pop;
          } else if (cur_clouds.size() == 1) {
            int cit = *cur_clouds.begin();
            gain[cit] += pop;
          }
          break;
      }
    }

    // output
    printf("%lld\n", already_sunny + *max_element(gain.begin(), gain.end()));
  }

  return 0;
}
