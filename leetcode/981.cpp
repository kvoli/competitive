#include <bits/stdc++.h>
using namespace std;
class TimeMap {
  public:
  /** Initialize your data structure here. */
  TimeMap() { }

  void set(string key, string value, int timestamp)
  {
    if (timeMap.find(key) == timeMap.end()) {
      map<int, string> newMap = { { timestamp, value } };
      timeMap[key] = newMap;
    } else {
      timeMap[key][timestamp] = value;
    }
  }

  string get(string key, int timestamp)
  {
    if (timeMap.find(key) == timeMap.end())
      return "";

    // get the respective mapping [timestamp] -> val for key

    // find the first t > timestamp
    auto ub = timeMap[key].upper_bound(timestamp);

    if (ub == timeMap[key].begin())
      return "";

    // return the previous element x = t-1
    return (*(--ub)).second;
  }

  private:
  unordered_map<string, map<int, string>> timeMap;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
