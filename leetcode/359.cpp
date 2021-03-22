#include <bits/stdc++.h>
using namespace std;
class Logger {
  public:
  /** Initialize your data structure here. */
  unordered_map<string, int> lastRequest;

  Logger()
  {
  }

  /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
  bool shouldPrintMessage(int timestamp, string message)
  {
    if (lastRequest.find(message) != lastRequest.end()) {
      if (lastRequest[message] > timestamp) {
        return false;
      }
    }
    lastRequest[message] = timestamp + 10;
    return true;
  }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
