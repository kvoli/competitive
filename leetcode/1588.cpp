#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
  int sumOddLengthSubarrays(vector<int>& arr)
  {
    int n, i, res;
    n = arr.size();

    res = 0;

    for (i = 0; i < n; ++i) {
      res += arr[i] * (ceil((i + 1) * (n - i) / 2.0));
    }

    return res;
  }
};
