#include <bits/stdc++.h>

using namespace std;
class SummaryRanges {
  public:
  /** Initialize your data structure here. */
  SummaryRanges()
  {
  }

  void addNum(int val)
  {
    // iterator to the first [start] > val
    auto it = dim.upper_bound(val);
    int lower, upper;
    pair<int, int> cur;
    vector<int> rms;
    lower = val;
    upper = val + 1;

    if (it != dim.end()) {
      cur = *it;
      if (val + 1 == cur.first) {
        lower = min(lower, cur.first);
        upper = max(upper, cur.second);
        cout << "val: " << val << ", "
             << "merge_upper: [" << cur.first << "," << cur.second << ") ==> [" << lower << "," << upper << ")" << endl;
        rms.push_back(cur.first);
      }
    }

    if (it != dim.begin()) {
      --it;
      cur = *it;
      if (val <= cur.second) {
        lower = min(lower, cur.first);
        upper = max(upper, cur.second);
        cout << "val: " << val << ", "
             << "merge_lower: [" << cur.first << "," << cur.second << ") ==> [" << lower << "," << upper << ")" << endl;
        rms.push_back(cur.first);
      }
    }
    for (int v : rms)
      dim.erase(v);

    dim[lower] = upper;
    cout << endl;
  }

  vector<vector<int>> getIntervals()
  {
    vector<vector<int>> res;
    for (auto const& p : dim)
      res.push_back({ p.first, p.second - 1 });
    return res;
  }

  private:
  map<int, int> dim;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
