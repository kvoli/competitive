#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
  vector<string> topKFrequent(vector<string>& words, int k)
  {
    unordered_map<string, int> fm;

    for (auto const& w : words) {
      if (fm.find(w) == end(fm))
        fm[w] = 1;
      else
        fm[w]++;
    }

    vector<pair<string, int>> rm(begin(fm), end(fm));

    nth_element(rm.begin(), rm.begin() + k, rm.end(), [](pair<string, int>& a, pair<string, int>& b) {
      if (a.second == b.second)
        return a.first > b.first;
      return a.second > b.second;
    });

    rm.resize(k);

    vector<string> res;
    for (auto const& e : rm)
      res.push_back(e.first);
    return res;
  }
};
