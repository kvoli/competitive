#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
class LFUCache {
  public:
  unordered_map<int, list<int>::iterator> mi;
  unordered_map<int, pii> mp;
  unordered_map<int, list<int>> fm;
  int leastFrequent, cap, size;

  LFUCache(int capacity)
  {
    cap = capacity;
    size = leastFrequent = 0;
  }

  int get(int key)
  {
    if (!exists(key))
      return -1;

    updateRank(key);
    return mp[key].first;
  }

  bool exists(int key)
  {
    return mp.find(key) != mp.end();
  }

  void updateRank(int key)
  {
    if (mi.find(key) != mi.end())
      fm[mp[key].second].erase(mi[key]);

    updateLeastFrequent();

    mp[key].second++;
    fm[mp[key].second].push_front(key);
    mi[key] = fm[mp[key].second].begin();
  }

  void evict()
  {
    auto evicted = --(fm[leastFrequent].end());
    int evictedKey = *evicted;
    fm[leastFrequent].erase(evicted);
    mi.erase(evictedKey);
    mp.erase(evictedKey);
    updateLeastFrequent();
    size--;
  }

  void updateLeastFrequent()
  {
    while (fm.find(leastFrequent) != fm.end() && fm[leastFrequent].size() == 0)
      leastFrequent++;
  }

  void put(int key, int value)
  {
    if (!exists(key)) {
      mp[key] = { value, 0 };
      leastFrequent = 1;
      size++;
    }
    mp[key].first = value;
    updateRank(key);
    while (size > cap)
      evict();
  }
};
