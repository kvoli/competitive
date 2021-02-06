#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
      int ax,ay,bx,by,n;
      n = nums.size();

      if (n == 0) return 0;
      if (n == 1) return nums[0];
      if (n < 2) {
        return nums[0] > nums[1] ? nums[0] : nums[1];
      }

      vector<int> dpx(nums.size(), 0);
      vector<int> dpy(nums.size(), 0);

      dpx[0] = nums[0];
      dpx[1] = nums[0];

      dpy[0] = 0;
      dpy[1] = nums[1];

      for (int i = 2; i < n; ++i) {

        ax = nums[i] + dpx[i-2];
        ay = nums[i] + dpy[i-2];

        bx = dpx[i-1];
        by = dpy[i-1];
        
        if (i >= n-1) {
          dpx[i] = bx;
          dpy[i] = ay > by ? ay : by;
        } else {
          dpx[i] = ax > bx ? ax : bx;
          dpy[i] = ay > by ? ay : by;
        }
      }

      return dpx[n-1] > dpy[n-1] ? dpx[n-1] : dpy[n-1];
    }
};
