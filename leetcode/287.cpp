#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

      vector<bool> seen (nums.size(),false);

      for (auto e: nums){
        if (seen[e] != 0) return e;
        seen[e] = true;
      }
      return -1;
    }
};
