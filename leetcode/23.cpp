/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      int n,i,k;

      n = lists.size();
      i = 1;

      while (i < n) {
        for (k = i; k < n-i; k*=2)  lists[i] = merge(lists[k], lists[k+i]);
        i*=2;
      }

      return n > 0 ? lists[0] ? nullptr;
    }
private:
    ListNode* merge(ListNode* a, ListNode* b) {
      if (!a) return b;
      if (!b) return a;
      if (a -> val < b -> val) { 
        a -> next = merge(a -> next, b);
        return a;
      }
      b -> next =  merge(a, b -> next);
      return b;
    }
};
