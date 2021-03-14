#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
  {

    unordered_map<string, vector<int>> mp;
    int i, j, n, m;

    n = accounts.size();

    for (i = 0; i < n; ++i) {
      m = accounts[i].size();
      for (j = 1; j < m; ++j) {
        if (mp.find(accounts[i][j]) == mp.end())
          mp[accounts[i][j]] = { i };
        else
          mp[accounts[i][j]].push_back(i);
      }
    }
  }
};
