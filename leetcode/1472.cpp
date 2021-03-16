#include <bits/stdc++.h>

using namespace std;

class BrowserHistory {
  public:
  BrowserHistory(string homepage)
  {
    history.push_back(homepage);
    n = i = 0;
  }

  void visit(string url)
  {
    if (i == n)
      history.push_back(url);
    history[++i] = url;
    n = i;
  }

  string back(int steps)
  {
    i = max(i - steps, 0);
    return history[i];
  }

  string forward(int steps)
  {
    i = min(i + steps, n);
    return history[i];
  }

  private:
  vector<string> history;
  int n, i;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
