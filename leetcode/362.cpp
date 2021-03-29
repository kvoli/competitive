#include <bits/stdc++.h>
using namespace std;
class HitCounter {
  public:
  /** Initialize your data structure here. */
  HitCounter()
  {
  }

  /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
  void hit(int timestamp)
  {
    timeMap[timestamp] = ++cur;
  }

  /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
  int getHits(int timestamp)
  {
    auto lb = timeMap.upper_bound(timestamp - 300);
    auto ub = timeMap.upper_bound(timestamp);

    int start = 0, end = cur;

    if (lb != timeMap.begin() && lb->first <= timestamp)
      start = prev(lb)->second;

    if (ub != timeMap.end())
      end = ub->second;

    return end - start;
  }

  private:
  map<int, int> timeMap;
  int cur = 0;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
