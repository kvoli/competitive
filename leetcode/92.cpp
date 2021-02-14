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
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
      ListNode* cur, next, prev;
      cur = head;
      prev = next = NULL;

      cnt = 0;

      while (++cnt < m) cur = cur -> next;
      

      while (cur != NULL && ++cnt <= n) {
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
      }

      return head;
    }
};
