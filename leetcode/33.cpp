class Solution {
public:
    int search(vector<int>& nums, int target) {

      int n, mid, l, r;
      n = nums.size();

      if (n == 0) return -1;
      if (n == 1) return nums[0] == target ? 0 : -1;

      l = 0;
      r = n-1;

      while (l <= r && nums[l] == nums[r]) {
        if (nums[l] == target) return true;
        l++;
        r--;
      }

      while (l <= r) {
        mid = l + (r - l) / 2;
        if (nums[mid] == target) return true;
        if (nums[mid] >= nums[l]) {
          if (target >= nums[l] && target <= nums[mid]) r = mid-1;
          else l = mid+1;
        } else {
          if (target <= nums[r] && target >= nums[mid]) l = mid+1;
          else r = mid-1;
        }
      }
      return false;
    }
};
