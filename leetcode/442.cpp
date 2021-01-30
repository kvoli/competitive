#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

      unordered_map<int, int> umap;
      vector<int> ret;

      for (auto e: nums) {
        umap[e] = umap[e] + 1;
      }

      
      for (auto e: umap) {
        if (e.second == 2) ret.push_back(e.first);
      }

      return ret;
    }
};
