#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  int maxScore(vector<int>& cardPoints, int k)
  {
    int n, start, res, cur, l, r;
    n = cardPoints.size();

    start = n - k;

    cur = res = 0;
    for (int i = 0; i < 2 * k; ++i) {
      r = (start + i) % n;
      l = (start + i - k) % n;
      cur += cardPoints[r];

      if (i >= k) {
        cur -= cardPoints[l];
      }

      res = max(cur, res);
    }
    return res;
  }
};
