#include <bits/stdc++.h>
using namespace std;
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

// binary search the rows starting at 0
// keep track of the leftmost Column in each binSearch,
//  -> subsequent bsearches can use this as an upperbound for speedup
//  -> worst case the element doesnt get found

// can do even better -> start at the top left, follow the algorithm
//    if (BinaryMatrix.get(row,col)) move left
//    else move down
//    O(n+m) solution guaranteed

class Solution {
  public:
  // each row is sorted, however they are not sorted by row + column e.g. [0,0,1]
  // want to return the column with the leftMost 1
  int leftMostColumnWithOne(BinaryMatrix& binaryMatrix)
  {
    int n, m, ret, i, j;
    vector<int> dims = binaryMatrix.dimensions();
    n = dims[0];
    m = dims[1];

    i = n - 1;
    j = m - 1;

    while (i >= 0 && j >= 0) {
      ret = binaryMatrix.get(i, j);
      if (ret == 1) {
        j--;
      } else {
        i--;
      }
    }
    return j != m - 1 ? j + 1 : -1;
  }
};
