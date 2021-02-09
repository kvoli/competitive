#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ret;
    void solve(vector<int>& choices, vector<int>& counts, vector<int>& cur, int start, int target)  {
      if (target == 0) {
        ret.push_back(cur);
        return;
      }

      for (int i = start; i < choices.size() && choices[i] <= target; ++i) {
        if (counts[i] > 0) {
          counts[i]--;
          cur.push_back(choices[i]);
          solve(choices, counts, cur, i, target - choices[i]);
          cur.pop_back();
          counts[i]++;
        } 
      }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      vector<int> cnts;
      vector<int> choice;
      vector<int> cur;
      int n, i, cnter;

      sort(candidates.begin(), candidates.end());

      cnter = 1;
      n = candidates.size();
      for (i = 1; i < n; ++i) {
        if (candidates[i] != candidates[i-1]) {
          choice.push_back(candidates[i-1]);
          cnts.push_back(cnter);
          cnter = 1;
        } else {
          cnter++;
        }
      }
      choice.push_back(candidates[n-1]);
      cnts.push_back(cnter);
        

      solve(choice, cnts, cur, 0, target);
      return ret;
    }
};
