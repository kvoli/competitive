#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> mirror;
    Node* copyRandomList(Node* head)
    {
        if (!head)
            return NULL;
        if (mirror[head] != NULL)
            return mirror[head];
        mirror[head] = new Node(head->val);
        mirror[head]->next = copyRandomList(head->next);
        mirror[head]->random = copyRandomList(head->random);
        return mirror[head];
    }
};
