#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

class Solution {
  public:
  int findLeastNumOfUniqueInts(vector<int>& arr, int k)
  {
    int n, m, i, res;
    unordered_map<int, int> mp;

    n = arr.size();

    for (auto const& v : arr)
      mp[v] = mp.find(v) != mp.end() ? mp[v] + 1 : 1;

    vector<pii> out(begin(mp), end(mp));
    m = out.size();
    sort(begin(out), end(out), [](pii& a, pii& b) { return a.second < b.second; });

    i = 0;
    while (k > 0) {
      if (out[i].second <= k) {
        k -= out[i].second;
        ++i;
      } else {
        break;
      }
    }
    cout << i << endl;
    return m - i;
  }
};
