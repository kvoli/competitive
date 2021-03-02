#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
      int j,i,x,y,dir,res;
      unordered_set<string> obs;
      for (vector<int>& v: obstacles) obs.emplace(to_string(v[0]) + "." +  to_string((v[1])));
      x=y=dir=res=0;
      vector<vector<int>> ds = {{0,1}, {1,0}, {0,-1}, {-1, 0}};
      for (i=0; i < commands.size(); ++i) {
        if (commands[i]==-2)dir--;
        else if (commands[i]==-1)dir++;
        else {
          for (j = 0; j < commands[i];++j) {
            if (obs.find(to_string(x+ds[dir][0]) + "." + to_string(y+ds[dir][1])) != obs.end()) break;
            x+= ds[dir][0]; y+= ds[dir][1];
          }
          res = max(res, x*x+y*y);
        }
        if (dir==-1)dir=3;
        if (dir==4)dir=0;
      }

      return res;
    }
};
