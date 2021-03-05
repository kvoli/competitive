#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

class Solution {
public:
    bool isRobotBounded(string instructions) {
      int x,y,d;
      x = y = d = 0;
      vector<pii> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
      for (char i: instructions) {
        if (i == 'G') {
          x += dirs[d].first;
          y += dirs[d].second;
        }
        else if (i == 'L') --d;
        else ++d;
        
        if (d == -1) d = 3;
        if (d == 4) d = 0;
      }
      return (d != 0 || (x + y) > 0);
    }
};
