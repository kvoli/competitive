#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ret;
    set<vector<int>> seen;

    void solve(vector<int>& candidates, int target, vector<int>& cur, int n) {
      if (target < 0) return;
      if (target == 0) {
        vector<int> tmp = cur;
        sort(tmp.begin(), tmp.end());
        if (seen.count(tmp)) return;
        ret.push_back(tmp);
        seen.insert(tmp);
        return;
      }

      for (int i = 0; i < n && candidates[i] <= target; ++i) {
        cur.push_back(candidates[i]);
        solve(candidates, target - candidates[i], cur, n);
        cur.pop_back();
      }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      int n;
      vector<int> cur;
      n = candidates.size();
      sort(candidates.begin(), candidates.end());
      solve(candidates, target, cur, n);
      return ret; 
    }
};
