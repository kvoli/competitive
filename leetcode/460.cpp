#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

class LFUCache {
  public:
  LFUCache(int capacity)
  {
    cap = capacity;
    size = 0;
  }

  int get(int key)
  {
    if (mp.count(key) == 0)
      return -1;

    fm[mp[key].second].erase(mi[key]);    // rm the entry for this key in the LRU list
    mp[key].second++;                     // update the frequency
    fm[mp[key].second].push_back(key);    // insert the updated frequency in new LRU list
    mi[key] = --fm[mp[key].second].end(); // set the iterator to be the end of list - 1

    if (fm[minFreq].size() == 0)
      minFreq++;

    return mp[key].first;
  }

  void put(int key, int value)
  {
    if (cap <= 0)
      return;

    if (get(key) != -1) {
      mp[key].first = value;
      return;
    }

    if (size >= cap) {
      mp.erase(fm[minFreq].front());
      mi.erase(fm[minFreq].front());
      fm[minFreq].pop_front();
      size--;
    }

    mp[key] = { value, 1 };
    fm[1].push_back(key);
    mi[key] = --fm[1].end();
    minFreq = 1;
    size++;
  }

  private:
  int cap, size, minFreq;
  unordered_map<int, pii> mp;
  unordered_map<int, list<int>::iterator> mi;
  unordered_map<int, list<int>> fm;
};
