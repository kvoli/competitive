class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
      int n, res = 0, i, end;
      n = points.size();
      if (n < 1) return res;
      sort(points.begin(), points.end());
      end = points[0][1];
      for (i = 1; i < n; ++i) {
        if (points[i][0] > end) {
          res++;
          end = points[i][1];
        } else 
            end = end > points[i][1] ? points[i][1] : end;
      }
      return ++res;
    }
};
