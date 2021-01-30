#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      
      int n, i;
      vector<int>  l,r,ret;

      n = nums.size();

      l = nums;
      r = nums;

      if (n < 1) {
        return ret;
      }

      if (n < 2){
        ret.push_back(0);
        return ret;
      };

      for (i = 1; i < n; ++i)
        l[i] = l[i] * l[i-1];


      for (i = n-2; i > -1; --i)
        r[i] = r[i] * r[i+1];

      ret.push_back(r[1]);

      for (i = 1; i < n-1; ++i)
        ret.push_back(r[i+1] * l[i-1]);

      ret.push_back(l[n-2]);

      return ret;
    }
};


int main(){
  return 0;

}
