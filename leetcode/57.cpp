#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool intersect(int a1, int a2, int b1, int b2) {
      int lo = max(a1, b1);
      int hi = min(a2, b2);
      return lo <= hi;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      vector<vector<int>> res(0, vector<int> (0,0));

      int n, start, end;
      n = intervals.size();

      start = newInterval[0];
      end = newInterval[1];

      for (auto e: intervals) {
        if (intersect(start, end, e[0], e[1])) {
          start = min(e[0], start);
          end = max(e[1], end);
        } else res.push_back(e);
      }

      res.push_back(vector<int>{start,end});
      sort(res.begin(), res.end());
      return res;
    }
};
