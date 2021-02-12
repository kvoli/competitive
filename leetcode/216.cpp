#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    void solve(int k, int sum, int start) {
      if (sum == 0 && k == 0) res.push_back(cur);
      if (sum == 0 || k == 0) return;

      for (int i = start; i < 10 && k > 0 && sum - i >= 0; ++i) {
        cur.push_back(i);
        solve(k-1, sum-i, i+1);
        cur.pop_back();
      }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
      if (k > 9 || n > 45) return res;
      solve(k, n, 1);
      return res;
    }
};
