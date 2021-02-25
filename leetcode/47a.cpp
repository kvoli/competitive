class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      dfs(0, nums.size(), nums);
      return res;
    }

private:
    vector<vector<int>> res;
    void dfs(int i, int n, vector<int> nums) {
      if (i == n-1) {
        res.push_back(nums);
        return;
      }

      for (int k = i; i < n; ++k) {
        if (k != i && nums[i] == nums[k]) continue;
        swap(nums[i], nums[k]);
        dfs(i+1, n, nums);
      }
    }
};
