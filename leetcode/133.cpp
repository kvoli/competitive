
class Solution {
public:
    Node* cloneGraph(Node* node) {
      if (node == NULL) return NULL;

      if (m.find(node) == m.end()) {
        m[node] = new Node(node -> val, {});
        for (Node* n : node -> neighbours) {
          m[node] -> neighbours.push_back(cloneGraph(n));
        }
      }
      return m[node];
    }
private:
    unordered_map<Node*, Node*> m;
};
