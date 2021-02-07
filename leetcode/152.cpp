#include <bits/stdc++.h>

using namespace std;

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)
#define MAXX(a, b, c) ((a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c))
#define MINN(a, b, c) ((a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c))

class Solution {
public:
    int maxProduct(vector<int>& nums) {

      int n, i, p_max, n_max;
      n = nums.size();
      vector<int> dpN(n, 0);
      vector<int> dpP(n, 0);
      dpN[0] = dpP[0] = p_max = n_max = nums[0];

      for (i = 1; i < n; ++i) {
        dpP[i] = MAXX(dpP[i-1] * nums[i], dpN[i-1] * nums[i], nums[i]);
        dpN[i] = MINN(dpP[i-1] * nums[i], dpN[i-1] * nums[i], nums[i]);
        p_max = MAX(dpP[i], p_max);
        n_max = MAX(dpN[i], n_max);
      }
      return MAX(p_max, n_max);
    }
};
