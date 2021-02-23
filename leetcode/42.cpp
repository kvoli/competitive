class Solution {
public:
    int trap(vector<int>& height) {
      int n,i,res;
      n = height.size();
      if (n == 0) return 0;
      res = 0;
      vector<int> lheights(n, 0);
      vector<int> rheights(n, 0);

      lheights[0] = height[0];
      rheights[n-1] = height[n-1];

      for (i = 1; i < n; ++i) lheights[i] = max(lheights[i-1], height[i]);
      for (i = n-2; i > -1; --i) rheights[i] = max(rheights[i+1], height[i]);
      for (i = 1; i < n; ++i) res += min(lheights[i], rheights[i]) - height[i];
      return res;
    }
};
