#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bsearch(vector<int>& nums, int l, int r, int target) {
      int mid;
      while (l < r) {
        mid = l + (r-l)/2;
        if (target == nums[mid]) return mid;
        else if (target > nums[mid]) l = mid+1;
        else r = mid-1;
      }
      return l;
    }

    bool closer(int x, int a, int b) {
      if (abs(x-a) < abs(x-b)) return true;
      if (abs(x-a) == abs(x-b)) return a < b;
      return false;
    }

    // [1,2,3,4,5]
    // 4,3
    //      3
    //    2,3
    //    2,3,4
    //  1,2,3,4  
    //
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
      int n,i,l,r,closest;
      vector<int> res(k,0);
      n = arr.size();
      closest = bsearch(arr, 0, n-1, x);

      l = max(0, closest - k - 1);
      r = min(n-1, closest+k - 1);

      while (r-l > k-1) {

        if (l < 0 || closer(x, arr[l], arr[r])) r--;
        else if (r > n-1 || closer(x, arr[r], arr[l]))l++;
        else return res;
      }

      for (i = 0; i < k; ++i) res[i] = arr[l+i];
      return res;
    }

};
