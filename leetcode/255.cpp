#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
  bool verifyPreorder(vector<int>& preorder)
  {
    return solve(preorder, INT_MIN, INT_MAX);
  }

  int i = 0;
  bool solve(vector<int>& A, int lb, int ub)
  {
    if (i == A.size() || A[i] > ub)
      return true;
    int mid = A[i++];
    return mid > lb && solve(A, lb, mid) && solve(A, mid, ub);
  }
};
