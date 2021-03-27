#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
  {
    int n, i;
    map<int, int> mp;
    vector<vector<int>> ret;
    n = startTime.size();

    for (i = 0; i < n; ++i) {
      ret.push_back({ endTime[i], startTime[i], profit[i] });
    }

    sort(begin(ret), end(ret));

    mp[0] = 0;

    for (auto const& job : ret) {
      int cur = prev(mp.upper_bound(job[1]))->second + job[2];
      if (cur > mp.rbegin()->second)
        mp[job[0]] = cur;
    }
    return mp.rbegin()->second;
  }
};
