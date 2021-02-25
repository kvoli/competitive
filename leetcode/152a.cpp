class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int n,i,negMax,posMax;
      n = nums.size();

      vector<int> pos(n, 1);
      vector<int> neg(n, 1);

      pos[0] = neg[0] = negMax = posMax = nums[0]

      for (i = 1; i < n; ++i) {
        pos[i] = max({pos[i-1] * nums[i], neg[i-1] * nums[i], nums[i]});
        neg[i] = min({pos[i-1] * nums[i], neg[i-1] * nums[i], nums[i]});
        negMax = max(neg[i], negMax);
        posMax = max(pos[i], posMax);
      }
      return max(posMax, negMax);
    }
};
