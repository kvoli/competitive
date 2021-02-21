#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      int cur, n, res, i;
      unordered_set<int> mp;
      for (int n:nums) mp.insert(n);
      res = 0;

      for (int n: nums) {
        if (mp.find(n-1) == mp.end()) {
          i = n;
          cur = 1;
          while (mp.find(i+1) != mp.end()) {
            cur++;
            i++;
          }
          res = res > cur ? res : cur;
        }
      }
      return res;
    }
};
