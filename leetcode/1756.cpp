#include <bits/stdc++.h>

using namespace std;

class MRUQueue {
  public:
  int size;
  list<int> q;
  MRUQueue(int n)
  {
    size = n;
    for (int i = 1; i <= n; ++i)
      q.push_back(i);
  }

  int fetch(int k)
  {
    auto it = q.begin();
    for (int i = 1; i < k; ++i, ++it)
      ;
    int val = *it;
    q.erase(it);
    q.push_back(val);
    return val;
  }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */
