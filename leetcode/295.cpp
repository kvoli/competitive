#include <bits/stdc++.h>
using namespace std;
class MedianFinder {
public:
  
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
      auto v = big.begin();
      if (v != big.end() && num > *v) big.emplace(num);
      else small.emplace(num);
      balance();
    }
    
    double findMedian() {
      int ssmall = small.size();
      int sbig = big.size();
      if (ssmall + sbig < 1) return 0;
      if ((ssmall + sbig) % 2 == 0) return (*(big.begin()) + *(--small.end()))/2.0;
      return (double)*(big.begin());
    }

private:
    multiset<int> big;
    multiset<int> small;

    void balance() {
      while (true) {
        int ssmall = small.size();
        int sbig = big.size();
        
        if (ssmall == sbig || ssmall + 1 == sbig) break;

        if (ssmall < sbig) {
          auto v = big.begin();
          small.emplace(*v);
          big.erase(v);
        } else {
          auto v = small.end();
          --v;
          big.emplace(*v);
          small.erase(v);
        }
      }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
