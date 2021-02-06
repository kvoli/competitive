#include <bits/stdc++.h>

using namespace std;


class Solution {
private:
    set<vector<int>> result;
    void ss(vector<int>& nums, vector<int> res, int k){
      if (k == nums.size()) {
        result.insert(res);
        return;
      }

      vector<int> new_res = res;
      new_res.push_back(nums[k]);
      sort(new_res.begin(), new_res.end());
      ss(nums, res, k+1);
      ss(nums, new_res, k+1);

    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<int> res;
      ss(nums, res, 0);
      vector<vector<int>> r(result.begin(), result.end());
      return r;
    }
};
