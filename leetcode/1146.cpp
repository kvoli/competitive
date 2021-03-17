#include <bits/stdc++.h>

using namespace std;

class SnapshotArray {
  unordered_map<int, unordered_map<int, int>> mp;
  int curSnap = 0;

  public:
  SnapshotArray(int length)
  {
    unordered_map<int, int> cur;
    mp[curSnap] = cur;
  }

  void set(int index, int val)
  {
    mp[curSnap][index] = val;
  }

  int snap()
  {
    unordered_map<int, int> nxt = mp[curSnap++];
    mp[curSnap] = nxt;
    return curSnap - 1;
  }

  int get(int index, int snap_id)
  {
    return mp[snap_id][index];
  }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
