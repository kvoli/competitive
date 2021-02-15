class Solution {
public:
    bool bsearch(vector<int>& nums, int target, int l, int r){
      int mid;
      while (l <= r) {
        mid = l + (r-l)/2;
        if (nums[mid] == target) return true;
        if (target > nums[mid]) l = mid+1;
        if (target < nums[mid]) r = mid-1;
      }
      return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int n,m,i;
      m = matrix.size();
      n = matrix[0].size();

      for (i = 0; i < m; ++i) {
        if (bsearch(matrix[i], target, 0, n-1)) return true;
      }
      return false;
    }
};
