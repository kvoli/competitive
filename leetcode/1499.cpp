#include <bits/stdc++.h>
#include <iterator>
using namespace std;
typedef pair<int, int> pii;
class Solution {
  public:
  int findMaxValueOfEquation(vector<vector<int>>& points, int k)
  {
    int n, i, res, cur;
    priority_queue<pii> maxHeap;

    n = points.size();

    res = INT_MIN;
    maxHeap.push(make_pair(points[0][1] - points[0][0], points[0][0]));

    for (i = 1; i < points.size(); i++) {
      cur = points[i][0] + points[i][1];

      while (!maxHeap.empty() && points[i][0] - maxHeap.top().second > k)
        maxHeap.pop();

      if (!maxHeap.empty())
        res = max(res, cur + maxHeap.top().first);

      maxHeap.push(make_pair(points[i][1] - points[i][0], points[i][0]));
    }

    return res;
  }
};
