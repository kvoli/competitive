#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
  {
    int res, i, n, amt;
    n = boxTypes.size();

    sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b) { return a[1] > b[1]; });

    i = res = 0;
    while (truckSize > 0 && i < n) {
      amt = min(boxTypes[i][0], truckSize);
      res += amt * boxTypes[i][1];
      truckSize -= amt;
      i++;
    }
    return res;
  }
};
