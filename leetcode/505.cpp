#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

class Solution {
  public:
  int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination)
  {
    n = maze.size();
    m = maze[0].size();
    return dfs(maze, { start[0], start[1] }, { destination[0], destination[1] }, 0);
  }

  int dfs(vector<vector<int>>& maze, pii start, pii dest, int applied)
  {
    if (seen.find(start) != seen.end())
      return INT_MAX;

    pii next = { -1, -1 };
    pii prev = start;
    int dist = 0;

    while ((next = apply(applied, prev, maze)) != prev) {
      prev = next;
      dist++;
    }

    if (next == dest)
      return dist;
    seen.insert(next);

    int best = INT_MAX;
    for (int i = 0; i < 4; ++i) {
      if (i == applied)
        continue;
      best = min(best, dfs(maze, apply(i, next, maze), dest, i));
    }

    return best + dist;
  }

  pii apply(int i, pii start, vector<vector<int>>& matrix)
  {
    pii next = { movements[i].first + start.first, movements[i].second + start.second };
    if (next.first >= n || next.first < 0 || next.second >= m || next.second < 0 || matrix[next.first][next.second]) {
      return start;
    }
    return next;
  }

  unordered_set<pii> seen;
  vector<pii> movements = { { 1, 0 }, { 0, 1 }, { 0, -1 }, { -1, 0 } };
  int n, m;
};
