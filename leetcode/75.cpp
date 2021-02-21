class Solution {
public:
    void sortColors(vector<int>& nums) {
      vector<int> cnt(3, 0);
      int n, i, k, j; 

      n = nums.size();
      k = 0;

      for (auto e: nums) cnt[e]++; 

      for (i = 0; i < n; ++i) {
        while (cnt[k] == 0) ++k;
        nums[i] = k;
        cnt[k]--;
      }
    }
};
