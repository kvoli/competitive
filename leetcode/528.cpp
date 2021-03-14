#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
  Solution(vector<int>& w)
  {
    total = 0;
    for (auto const e : w) {
      total += e;
      prefixSum.push_back(total);
    }
  }

  int pickIndex()
  {
    int r = rand() % total;
    return distance(begin(prefixSum), lower_bound(begin(prefixSum), end(prefixSum), r)) - 1;
  }

  private:
  vector<int> prefixSum;
  int total;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
