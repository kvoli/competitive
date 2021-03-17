#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
class Employee {
  public:
  int id;
  int importance;
  vector<int> subordinates;
};

class Solution {
  public:
  int getImportance(vector<Employee*> employees, int id)
  {
    unordered_map<int, Employee*> mp;

    for (auto e : employees) {
      mp[e->id] = e;
    }

    return dfs(mp, id);
  }

  int dfs(unordered_map<int, Employee*>& employees, int id)
  {
    int total;

    Employee* top = employees[id];
    total = top->importance;

    for (auto const& i : top->subordinates) {
      total += dfs(employees, i);
    }

    return total;
  }
};
