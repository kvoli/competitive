#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

      vector<vector<int>> res(0, vector<int>(0, 0));
      if (nums1.empty() || nums2.empty() || k < 1) return res;

      auto comp = [&nums1, &nums2](pair<int,int> a, pair<int,int> b) {
        return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
      };
      priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> min_heap(comp);
      min_heap.emplace(0, 0);
      while(k-- > 0 && min_heap.size()) {
        auto idx = min_heap.top();min_heap.pop();
        res.push_back(vector<int> {nums1[idx.first], nums2[idx.second]});
        if (idx.first + 1 < nums1.size()) min_heap.emplace(idx.first + 1, idx.second);
        if (idx.first == 0 && idx.second + 1 < nums2.size()) min_heap.emplace(idx.first, idx.second + 1);
      }
      return res;
    }
};
