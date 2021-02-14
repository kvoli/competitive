class Solution {
public:
    int findMin(vector<int>& nums) {
      int l, r, mid;

      l = 0;
      if (nums.size() == 1) return nums[0];
      
      r = nums.size()-1;
      
      if (nums[l] < nums[r]) return nums[l];
      while (l <= r) {
        mid = l + (r - l) / 2;
        if (nums[mid] > nums[mid+2]) return nums[mid+1];
        if (nums[mid-1] > nums[mid]) return nums[mid];

        if (nums[mid] > nums[l]) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
      return -1;
    }
};
