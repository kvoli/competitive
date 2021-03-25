#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  int numTeams(vector<int>& rating)
  {
    int i, j, k, n, res;
    set<int> seen;
    res = 0;
    n = rating.size();

    seen.insert(rating[i]);

    for (i = 1; i < n - 1; ++i) {
      auto ub = seen.upper_bound(rating[i]);
      k = distance(seen.begin(), ub);
      for (j = i + 1; j < n; ++j) {
        if (rating[i] < rating[j]) // how many elements < rating[i] ?
          res += k;
        if (rating[i] > rating[j]) // how many elements > rating[i] ?
          res += i - k;
      }
      seen.insert(rating[i]);
    }
    return res;
  }
};
