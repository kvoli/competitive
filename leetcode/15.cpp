#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

      int n, i, k, j, sum, target;
      vector<vector<int>> res;
      n = nums.size();
      sort(begin(nums), end(nums));

      for (i = 0; i < n - 2; ++i) {
        if ((i > 0 && nums[i] != nums[i-1]) || i == 0) {
          j = i + 1;
          k = n - 1;
          target = -nums[i];
          while (j < k) {
            sum = nums[j] + nums[k];
            if (sum < target)++j;
            else if (sum > target)--k;
            else {
              res.push_back({nums[j], nums[i], nums[k]});
              while (j < k && nums[j] == nums[j+1]) ++j;
              while (k > j && nums[k] == nums[k-1]) --k;
              j++;
              k--;
            }
          }
        }
      }
      return res;
    }
};
