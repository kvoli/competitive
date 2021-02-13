#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
      
      vector<int> res(num+1, 0);

      // [0,2,4,6,8,10,12,14,16]
      // [0,1,1,2,1, 2, 2, 3, 1]
      // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]
      // [0,1,1,2,1,2,2,3,1,2, 2, 3, 2, 3, 3, 4, 1]

      int prev_bound = 1;
      int power_bound = 2;
      for (int i = 1; i <= num; ++i) {
        if (i % 2 != 0) res[i] = res[i-1] + 1;
        else {
          if (i == power_bound) {
            res[i] = 1;
            prev_bound = power_bound;
            power_bound *= 2;
          } else {
            res[i] = res[i - prev_bound] + 1;
          }
        }
      }
      return res;
    }
};
