#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
#define iterator vector<vector<int>>::iterator

class Solution {
  public:
  vector<int> countSmaller(vector<int>& nums)
  {
    int n, i, idx;
    vector<vector<int>> zipped;
    n = nums.size();
    vector<int> count(0, n);
    for (i = 0; i < n; ++i)
      zipped.push_back(vector<int>({ nums[i], i }));
    sort_count(zipped.begin(), zipped.end(), count);
    return count;
  }

  private:
  void sort_count(iterator l, iterator r, vector<int>& count)
  {
    if (r - l <= 1)
      return;
    iterator m = l + (r - l) / 2;
    sort_count(l, m, count);
    sort_count(m, r, count);
    for (iterator i = l, j = m; i < m; i++) {
      while (j < r && (*i)[0] > (*j)[0])
        ++j;
      count[(*j)[1]] += j - m;
    }
    inplace_merge(l, m, r);
  }
};
