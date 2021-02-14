class Solution {
public:
    bool bsearch(vector<int>& nums, int target, int l, int r) {
      int mid;
      while (l <= r) {
        mid = l + (r - l) / 2;
        if (nums[mid] == target)return true;
        if (nums[mid] > target)r = mid-1;
        else l = mid+1;
      }
      return false;
    }

    int minE(vector<int>& nums, int l, int r) {
      if (nums[l] <= nums[r]) return l;

      int mid;
      while (l <= r) {
        mid = l + (r - l) / 2;
        if (nums[mid+1] > nums[mid]) return mid+1;
        if (nums[mid] > nums[l]) l = mid+1;
        else r = mid - 1;
      }
      return mid;
    }

    bool search(vector<int>& nums, int target) {

      int n, pivot;
      n = nums.size();

      if (n == 0) return false;
      if (n == 1) return nums[0] == target;

      pivot = minE(nums, 0, n-1);

      if (nums[pivot] == target) return true;
      if (pivot == 0) return bsearch(nums, target, 0, n-1);
      if (nums[0] > target) return bsearch(nums, target, pivot, n-1);
      return bsearch(nums, target, 0, pivot);
    }
};
