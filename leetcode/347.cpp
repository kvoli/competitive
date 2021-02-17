class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int,int> mp;
      vector<pair<int,int>> rt;
      vector<int> res;

      for(auto e: nums) mp[e]++;

      for(pair<int,int> p: mp) rt.push_back(p);

      nth_element(rt.begin(), rt.begin()+K, rt.end(), [](pair<int,int> &a, pair<int,int> &b){
          return a.second < b.second;
          });
      
      for(int i = 0 ; i < K; ++i) res.push_back(rt[i].first);
      return res;
    }
};
