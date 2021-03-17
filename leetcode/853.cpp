#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
class Solution {
  public:
  int carFleet(int target, vector<int>& position, vector<int>& speed)
  {
    int i, n, res;
    vector<pdi> trips;

    n = position.size();

    if (n < 2)
      return n;

    for (i = 0; i < n; ++i)
      trips.push_back(make_pair((target - position[i] * 1.0) / speed[i], position[i]));

    sort(begin(trips), end(trips), [](pdi& a, pdi& b) { return a > b; });

    res = 1;
    for (i = 0; i < n - 1; ++i) {
      if (trips[i].second < trips[i + 1].second)
        res++;
      else {
        trips[i + 1].first = trips[i].first;
        trips[i + 1].second = trips[i].second;
      }
    }

    return res;
  }
};
