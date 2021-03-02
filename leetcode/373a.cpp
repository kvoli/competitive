
typedef pair<int,int> pii;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

      int n1,n2,i,j;
      vector<vector<int>> res;
        
      n1 = nums1.size();
      n2 = nums2.size();

      if (n1 == 0 || n2 == 0 || k < 1) return res;

      auto comp = [&nums1, &nums2] (pii a, pii b) {
        return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
      };

      priority_queue<pii, vector<pii>, decltype(comp)> pq(comp);

      pq.emplace(0,0);

      while (k-- && !pq.empty()) {
        i = pq.top().first;
        j = pq.top().second;
        pq.pop();

        res.push_back({nums1[i], nums2[j]});
        if (i < n1-1) pq.emplace(i+1, j);
        if (i == 0 && j < n2-1) pq.emplace(i, j+1);
      }
      return res;
    }
};
