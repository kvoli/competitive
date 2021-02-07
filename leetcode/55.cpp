#include <bits/stdc++.h>

#define MIN(a, b) (a > b ? b : a)

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
      int n, i, g_index;
      n = nums.size();
      g_index = n-1;

      for (i = n-2; i > -1; --i) {
        if (i + nums[i] >= g_index) g_index = i;
      }

      return g_index == 0;
    }
};
