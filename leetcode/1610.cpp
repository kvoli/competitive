#include <bits/stdc++.h>
#include <math.h>

using namespace std;

#define EPS 1e-9
#define PI 3.14159265

class Solution {
  public:
  // brute force
  // best = 0
  // for d in [0, 359]
  //     cur = 0
  //     for p in points:
  //        if (angle(p, d, angle))
  //          cur += 1
  //     best = max(best, cur)
  // return best
  //
  //
  //
  // better (pre calc angles for all p in points)
  int common = 0;

  int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location)
  {
    int l, r, n, i, top, dx, dy, common;
    vector<double> angles;

    common = 0;
    for (auto& p : points) {
      dx = p[0] - location[0];
      dy = p[1] - location[1];
      if (dx == 0 && dy == 0)
        common++;
      else
        angles.push_back(calcAngle(dx, dy));
    }

    n = angles.size();
    sort(begin(angles), end(angles));

    for (i = 0; i < n; ++i)
      angles.push_back(angles[i] + 360);

    l = r = top = 0;

    while (r < 2 * n) {
      if (angles[r] - angles[l] <= angle + EPS) {
        top = max(top, r - l + 1);
        ++r;
      } else
        ++l;
    }

    return top + common;
  }

  double calcAngle(int dx, int dy)
  {
    double d = atan2(dy, dx) * 180 / PI;
    return d < 0 ? d + 360 : d;
  }
};
