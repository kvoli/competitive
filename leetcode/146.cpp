#include <bits/stdc++.h>

using namespace std;

class LRUCache {
  public:
  unordered_map<int, int> mp;
  unordered_map<int, list<int>::iterator> queueMap;
  list<int> usedQueue;
  int size, cap;

  LRUCache(int capacity)
  {
    cap = capacity;
    size = 0;
  }

  int get(int key)
  {
    int ret = -1;
    if (mp.find(key) != mp.end()) {
      ret = mp[key];
      update_rank(key);
    }
    return ret;
  }

  void update_rank(int key)
  {
    if (queueMap.find(key) != queueMap.end()) {
      usedQueue.erase(queueMap[key]);
    }
    usedQueue.push_front(key);
    queueMap[key] = usedQueue.begin();
  }

  void evict()
  {
    int lastKey = usedQueue.back();
    usedQueue.pop_back();
    mp.erase(lastKey);
    queueMap.erase(lastKey);
    size--;
  }

  void put(int key, int value)
  {
    if (mp.find(key) == mp.end())
      size++;

    update_rank(key);
    mp[key] = value;

    while (size > cap)
      evict();
  }
};
