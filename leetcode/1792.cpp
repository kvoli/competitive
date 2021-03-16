#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
  double maxAverageRatio(vector<vector<int>>& classes, int extraStudents)
  {
    // loop throught and see what increases the average the most at each step
    int n, i, j;
    double cur;

    auto comp = [&classes](int a, int b) {
      return (classes[a][0] + 1.0) / (classes[a][1] + 1.0) - (classes[a][0] * 1.0) / (classes[a][1]) < (classes[b][0] + 1.0) / (classes[b][1] + 1.0) - (classes[b][0] * 1.0) / (classes[b][1]);
    };

    priority_queue<int, vector<int>, decltype(comp)> min_heap(comp);

    for (i = 0; i < classes.size(); ++i) {
      min_heap.push(i);
    }

    for (i = 0; i < extraStudents; ++i) {
      j = min_heap.top();
      min_heap.pop();
      classes[j][0]++;
      classes[j][1]++;
      min_heap.push(j);
    }

    cur = 0;
    for (auto const& v : classes)
      cur += v[0] * 1.0 / v[1];

    return (cur / classes.size());
  }
};
