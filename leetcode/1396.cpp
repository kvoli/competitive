#include <bits/stdc++.h>
using namespace std;
class UndergroundSystem {
typedef pair<string,int> psi;
typedef pair<int,int> pii;
  
public:
    
    UndergroundSystem() {
         
    }
    
    void checkIn(int id, string stationName, int t) {
      customers[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
      psi stationTime = customers[id];
      string key = stationTime.first + "#" + stationName;
      pii total = {0,0};
      if (totals.find(key) != totals.end())  total = totals[key];
      total.first++;
      total.second += (t - stationTime.second);
      totals[key] = total;
      customers.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
      string key = startStation + "#" + endStation;
      pii total = totals[key];
      return total.second / (double) total.first;
    }

private:
    unordered_map<int,psi> customers;
    unordered_map<string,pii> totals;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
