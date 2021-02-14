#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      int  i, j, res, n, pre;
      sort(intervals.begin(), intervals.end());
      n = intervals.size();

      res = pre = 0;

      for (i = 1; i < n; ++i){ 
        if (intervals[i][0] < intervals[pre][1]) {
          res++;
          if (intervals[i][1] < intervals[pre][1]) pre = i;
        }
        else pre = i;
      }
      return res;
    }
};
