#include <bits/stdc++.h>
#include <iterator>

using namespace std;

class Solution {
  public:
  int lengthOfLISdp(vector<int>& nums)
  {
    int i, j, n, res;
    res = 0;
    n = nums.size();
    vector<int> dp(n, 1);

    for (i = 0; i < n; ++i) {
      for (j = 0; j < i; ++j) {
        if (nums[j] < nums[i] && dp[j] >= dp[i])
          dp[i] = dp[j] + 1;
      }
      res = res > dp[i] ? res : dp[i];
    }
    return res;
  }

  int lengthOfLIS(vector<int>& nums)
  {
    int n, i, res;
    vector<vector<int>> piles;
    vector<int> botPiles;

    n = nums.size();
    // patience sort
    for (i = 0; i < n; ++i) {
      int idx = findStack(botPiles, nums[i]);
      if (idx == -1) {
        piles.push_back({ nums[i] });
        botPiles.push_back(nums[i]);
      } else {
        piles[idx].push_back(nums[i]);
        botPiles[idx] = nums[i];
      }
    }
    return piles.size();
  }

  int findStack(vector<int>& stacks, int key)
  {

    auto it = lower_bound(begin(stacks), end(stacks), key);
    if (it == stacks.end())
      return -1;

    return it - begin(stacks);
  }
};
