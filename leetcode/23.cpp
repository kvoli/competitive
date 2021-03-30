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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        int n, skip, k;

        n = lists.size();
        skip = 1;

        while (skip < n) {
            for (k = 0; k < n - skip; k += skip * 2)
                lists[k] = merge(lists[k], lists[k + skip]);
            skip *= 2;
        }

        return n > 0 ? lists[0] : nullptr;
    }

    ListNode* merge(ListNode* a, ListNode* b)
    {
        if (!a)
            return b;
        if (!b)
            return a;
        if (a->val < b->val) {
            a->next = merge(a->next, b);
            return a;
        }

        b->next = merge(a, b->next);
        return b;
    }
};
