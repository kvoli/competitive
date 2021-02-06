#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    set<vector<int>> result;
    void heaps(vector<int>& nums, int k) {
      if (k == 1) {
        vector<int> cpy = nums;
        result.insert(cpy);
      }

      for (int i = 0; i < k; ++i) {
        heaps(nums, k-1);
        if (k % 2 == 1)  swap(nums[0], nums[k - 1]);
        else 
          swap(nums[i], nums[k-1]);
      }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
      heaps(nums, nums.size());
      vector<vector<int>> r(result.begin(), result.end());
      return r;
  }
};
