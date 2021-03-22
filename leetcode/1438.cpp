#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  int longestSubarray(vector<int>& nums, int limit)
  {
    multiset<int> minmax;
    int start, end, n, res;
    n = nums.size();

    start = end = res = 0;
    while (end < n) {
      minmax.insert(nums[end]);
      cout << *(--minmax.end()) << ", " << *minmax.begin() << endl;
      while (*(--minmax.end()) - *minmax.begin() > limit && start < end) {
        minmax.erase(minmax.find(nums[start++]));
        cout << "erased: " << nums[start - 1] << endl;
      }

      res = max(res, end - start + 1);
      end++;
    }
    return res;
  }
};
