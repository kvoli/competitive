#include <bits/stdc++.h>

using namespace std;
class Solution {
  public:
  int findCircleNum(vector<vector<int>>& isConnected)
  {
    int ret = 0;
    for (int i = 0; i < isConnected.size(); ++i) {
      if (seen.find(i) == seen.end()) {
        ++ret;
        dfs(isConnected, i);
      }
    }
    return ret;
  }

  unordered_set<int> seen;

  void dfs(vector<vector<int>>& g, int i)
  {
    seen.insert(i);

    for (int j = 0; j < g[i].size(); ++j) {
      if (g[i][j] == 0 || seen.find(j) != seen.end())
        continue;
      g[i][j] = 0;
      g[j][i] = 0;
      dfs(g, j);
    }
  }
};
