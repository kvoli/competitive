#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
  int minimumEffortPath(vector<vector<int>>& heights)
  {
    int left = 0;
    int right = 1000000;
    int result = right;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (dfsUtil(heights, mid)) {
        result = min(result, mid);
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return result;
  }

  int directions[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
  bool dfsUtil(vector<vector<int>>& heights, int mid)
  {
    int row = heights.size();
    int col = heights[0].size();
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    return canReachDestinaton(0, 0, heights, visited, row, col, mid);
  }

  bool canReachDestinaton(int x, int y, vector<vector<int>>& heights,
      vector<vector<bool>>& visited, int row, int col,
      int mid)
  {
    if (x == row - 1 && y == col - 1) {
      return true;
    }
    visited[x][y] = true;
    for (auto direction : directions) {
      int adjacentX = x + direction[0];
      int adjacentY = y + direction[1];
      if (isValidCell(adjacentX, adjacentY, row, col) && !visited[adjacentX][adjacentY]) {
        int currentDifference = abs(heights[adjacentX][adjacentY] - heights[x][y]);
        if (currentDifference <= mid) {
          if (canReachDestinaton(adjacentX, adjacentY, heights,
                  visited, row, col, mid))
            return true;
        }
      }
    }
    return false;
  }

  bool isValidCell(int x, int y, int row, int col)
  {
    return x >= 0 && x <= row - 1 && y >= 0 && y <= col - 1;
  }
};
