#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

class Solution {
  public:
  vector<int> countSmaller(vector<int>& nums)
  {
    int n, i, idx;

    n = nums.size();
    vector<int> res(0);
    multiset<int> s;

    for (i = n - 1; i >= 0; --i) {
      auto it = s.upper_bound(nums[i]);
      auto c = s.count(nums[i]);
      auto d = distance(begin(s), it);
      s.insert(nums[i]);
      cout << d << endl;
      nums[i] = d - c;
    }

    return nums;
  }
};
