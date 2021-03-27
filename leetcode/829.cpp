#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  int consecutiveNumbersSum(int N)
  {
    int res, k, i, limit;

    res = 0;

    limit = trunc(sqrt(2 * N + 0.25) - 0.5);

    for (k = 1; k <= limit; ++k) {
      if ((N - k * (k + 1) / 2) % k == 0)
        ++res;
    }
    return res;
  }
};
