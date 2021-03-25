#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

class Solution {

  public:
  // handle case where == 60
  int numPairsDivisibleBy60(vector<int>& time)
  {
    int check, m, n, i, res, l, r, x, checkSplit;
    map<int, int> mod;
    n = time.size();
    res = check = checkSplit = 0;
    for (i = 0; i < n; ++i) {
      x = time[i] % 60;
      if (x == 0) {
        check++;
      } else if (x == 30) {
        checkSplit++;
      } else {
        mod[x]++;
      }
    }

    vector<pair<int, int>> ret(mod.begin(), mod.end());
    l = 0;
    m = ret.size();
    r = m - 1;

    while (l <= r) {
      auto tmp = ret[l].first + ret[r].first;
      if (tmp == 60)
        res += ret[l].second * ret[r].second;
      if (tmp > 60)
        --r;
      else
        ++l;
    }
    return res + pairs(check) + pairs(checkSplit);
  }

  private:
  int pairs(int n)
  {
    return (n * (n - 1)) / 2;
  }
};
