class Solution {
public:
    int maxArea(vector<int>& height) {
      int l,r,n,best,cur;

      n = height.size();
      best = l = 0;
      r = n-1;

      while (l < r) {
        cur = area(l, r, height[l], height[r]);
        best = best > cur ? best : cur;
        if (height[l] < height[r]) {
          ++l;
        } else if (height[l] > height[r]) {
          --r;
        } else {
          ++l;
          --r;
        }
      }
      return best;
    }

private:
    int area(int l, int r, int h1, int h2) {
      return (r-l) * min(h1, h2);
    }
};
