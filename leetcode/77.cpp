#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> val;
    void dfs(int start, int num, int n, int k) {
      if (num == k) {
        res.push_back(val);
        return;
      }
      for (int i = start; i < n; ++i)  {
        val.push_back(i+1);
        dfs(i+1, num+1, n, k);
        val.pop_back();
      }
    }

    vector<vector<int>> combine(int n, int k) {
      if (n < k) return res;
      val.resize(k);
      dfs(0, 0, n, k);
      return res;
    }
};
