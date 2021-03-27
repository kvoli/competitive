#include <bits/stdc++.h>
using namespace std;
class TweetCounts {
  public:
  TweetCounts()
  {
  }

  void recordTweet(string tweetName, int time)
  {
    if (tweetRanges.find(tweetName) == tweetRanges.end()) {
      map<int, int> newMap;
      newMap[time] = 1;
      tweetRanges[tweetName] = newMap;
    } else {
      tweetRanges[tweetName][time]++;
    }
  }

  vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime)
  {
    if (tweetRanges.find(tweetName) == tweetRanges.end())
      return {};
    vector<int> res;
    auto lb = tweetRanges[tweetName].lower_bound(startTime);
    auto ub = tweetRanges[tweetName].upper_bound(endTime);
    double unit;
    int windowCount;

    if (freq == "minute")
      unit = 60;
    else if (freq == "hour") {
      unit = 3600;
    } else {
      unit = 86400;
    }

    for (int i = 0; (unit * i) + startTime <= endTime; ++i) {
      windowCount = 0;
      while (lb != ub && lb->first < unit * (i + 1) + startTime) {
        for (int j = 0; j < lb->second; ++j) {
          windowCount++;
        }
        ++lb;
      }
      res.push_back(windowCount);
    }
    return res;
  }

  private:
  unordered_map<string, map<int, int>> tweetRanges;
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
