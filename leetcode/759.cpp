#include <bits/stdc++.h>
#include <iterator>

using namespace std;

class Interval {
  public:
  int start;
  int end;

  Interval() { }

  Interval(int _start, int _end)
  {
    start = _start;
    end = _end;
  }
};

class Solution {
  public:
  vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule)
  {
    vector<vector<int>> events;
    for (auto const& employee : schedule) {
      for (auto const& shift : employee) {
        events.push_back({ shift.start, 0 });
        events.push_back({ shift.end, 1 });
      }
    }

    sort(begin(events), end(events), [](vector<int>& a, vector<int>& b) {
      return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];
    });

    vector<Interval> res;
    int prev = -1, bal = 0;

    for (auto const& event : events) {
      if (bal == 0 && prev >= 0) {
        res.emplace_back(prev, event[0]);
      }
      bal += event[1] == 0 ? 1 : -1;
      prev = event[0];
    }
    return res;
  }
};
