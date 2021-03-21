#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
class Solution {
  public:
  string alphabetBoardPath(string target)
  {

    int n, dx, dy, i, diff;
    char cur;

    string res = "";

    n = target.size();

    cur = 'a';

    for (auto const& letter : target) {
      diff = (letter - 'a') - (cur - 'a');
      pii x, y;

      x = getIndices(cur);
      y = getIndices(letter);

      dx = y.first - x.first;
      dy = y.second - x.second;

      if (cur == 'z') {
        // if at z we have to do horizontal movement last
        while (dy < 0)
          res += "U", ++dy;
        while (dx > 0)
          res += "R", --dx;
      } else {
        // else we just do it first
        while (dx > 0)
          res += "R", --dx;
        while (dx < 0)
          res += "L", ++dx;
        while (dy > 0)
          res += "D", --dy;
        while (dy < 0)
          res += "U", ++dy;
      }
      cur = letter;
      res += "!";
    }
    return res;
  }

  private:
  pii getIndices(char c)
  {
    return { (c - 'a') % 5, (c - 'a') / 5 };
  }
};
