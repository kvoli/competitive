#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
  int minSwap(vector<int>& A, vector<int>& B)
  {
    int n, i, swap, nswap, swap2, nswap2;

    n = A.size();
    swap = 1;
    nswap = 0;

    for (i = 1; i < n; ++i) {
      nswap2 = n, swap2 = n;
      if (A[i - 1] < A[i] && B[i - 1] < B[i]) {
        swap2 = swap + 1;
        nswap2 = nswap;
      }

      if (A[i - 1] < B[i] && B[i - 1] < A[i]) {
        swap2 = min(swap2, nswap + 1);
        nswap2 = min(nswap2, swap);
      }
      swap = swap2;
      nswap = nswap2;
    }

    return min(swap, nswap);
  }
};
