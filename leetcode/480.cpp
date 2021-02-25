#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
      multiset<int> window(nums.begin(), nums.begin() + k);
      auto mid = next(window.begin(),k/2);
      vector<double> res;
      int n = nums.size();

      for (int i = k; i < n; ++i) {
        res.push_back((double(*mid) + *prev(mid, 1-k%2)) / 2);

        window.insert(nums[i]);

        if (nums[i] < *mid)
          --mid;

        if (nums[i-k] <= *mid)
          ++mid;

        window.erase(window.lower_bound(nums[i-k]));
      }

      res.push_back((double(*mid) + *prev(mid, 1-k%2)) / 2);
      return res;
    }
};
