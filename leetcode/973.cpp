#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double distance(vector<int> a) {
      return sqrt((a[0]*a[0]) + (a[1]*a[1]));
    }

    bool compare(vector<int> a, vector<int> b) {
      return distance(a) > distance(b);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
      nth_element(points.begin(), points.begin()+K, points.end(), [](vector<int> &a, vector<int> &b) {
            return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];
            });
      points.resize(K);
      return points;

        
    }
};
