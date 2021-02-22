class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long long> mp;
        int res = 0, i;
        long long left, right, sum = 0;
        for (i = 0, mp.insert(0), i < nums.size(); ++i) {
          sum += nums[i];
          res += distance(mp.lower_bound(sum - upper), mp.upper_bound(sum - lower));
          mp.insert(sum);
        }
        return res;
    }
};
