class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<int> cur;
      int n = nums.size();
      sort(begin(nums), end(nums));
      solve(nums, cur, 0);
      return res;
    }
private:
    vector<vector<int>> res;

    void solve(vector<int>& nums, vector<int>& cur, int start) {
      res.push_back(cur);
      for (int i = start; i < nums.size(); ++i) {
        if (i != start && nums[i] == nums[i-1]) continue;
        cur.push_back(nums[i]);
        solve(nums, cur, i+1);
        cur.pop_back();
      }

    }
};
