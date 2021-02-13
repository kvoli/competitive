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
    int llength(ListNode* head) {
      return head ? llength + 1: 0;
    }

    ListNode* solve(ListNode* head, int n) {
      if (n == 0 && head != NULL) return head -> next;
      head -> next = solve(head -> next, n-1);
      return head;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
      int length = llength(head);
      return solve(head, length - n);
    }
};
