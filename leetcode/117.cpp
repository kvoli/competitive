class Solution {
public:
    Node* connect(Node* root) {
      Node *now, *tail, *head;
      // head is the left most element at the next level
      // tail is the right most element at the next level we've seen so far
      // now is the current node we are looking at (at a level above head and tail)

      now = root;
      tail = head = NULL;

      while (now)
      {
        if (now -> left)
          if (tail) tail = tail -> next = now -> left;
          else head = tail = now -> left;
        if (now -> right)
          if (tail) tail = tail -> next = now -> right;
          else head = tail = now -> right;
        if (!(now = now -> next)) {
          now = head;
          head = tail = NULL;
        }
      }
      return root;
    }
};
