#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
  int leastBricks(vector<vector<int>>& wall)
  {
    unordered_map<int, int> freqs;
    int i, n, ret, cur;

    n = wall.size();

    for (auto const& layer : wall) {
      cur = 0;
      for (auto const& brick : layer) {
        cur += brick;
        freqs[cur]++;
      }
      freqs.erase(cur);
    }

    int mx = 0;

    for (auto const& p : freqs) {
      mx = max(mx, p.second);
    }
    return n - mx;
  }
};
