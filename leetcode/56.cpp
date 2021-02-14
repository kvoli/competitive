#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

      int start, end, i, n;
      vector<vector<int>> res(0, vector<int> (0,0));
      n = intervals.size();
      if (n < 1) return res;
      sort(intervals.begin(), intervals.end());

      start = intervals[0][0];
      end = intervals[0][1];

      for (i = 1; i < n; ++i) {
        if (intervals[i][0] <= end) end = intervals[i][1] > end ? intervals[i][1] : end;
        else {
          res.push_back(vector<int> {start, end});
          start = intervals[i][0];
          end = intervals[i][1];
        }
      }
      res.push_back(vector<int> {start, end});
      return res;
    }
};
