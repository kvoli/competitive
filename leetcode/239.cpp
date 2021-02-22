#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      int i,n;
      vector<int> res;
      deque<int> dq;
      n = nums.size();
      for (i = 0; i < n; ++i) {
        if (!dq.empty() && dq.front() == i-k) dq.pop_front();
        while (!dq.empty() && nums[dq.back() <= nums[i]]) dq.pop_back();
        dq.push_back(i);
        if (i >= k-1) res.push_back(nums[dq.front()]);
      }
      return res;
    }
};



// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation:
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
 // 1 [3  -1  -3] 5  3  6  7       3
 // 1  3 [-1  -3  5] 3  6  7       5
 // 1  3  -1 [-3  5  3] 6  7       5
 // 1  3  -1  -3 [5  3  6] 7       6
 // 1  3  -1  -3  5 [3  6  7]      7
