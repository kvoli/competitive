#include <bits/stdc++.h>

using namespace std;


class Solution {
private:
    vector<vector<int>> result;
    void ss(vector<int>& nums, vector<int> res, int k){
      if (k == nums.size()) {
        result.push_back(res);
        return;
      }

      vector<int> new_res = res;
      new_res.push_back(nums[k]);
      ss(nums, res, k+1);
      ss(nums, new_res, k+1);

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<int> res;
      ss(nums, res, 0);
      return result;
    }
};
