class Solution {
  public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> visited;
        return dfs(node, visited);
    }

  private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& visited) {
        // If the node is already cloned, return its clone
        if (visited.find(node) != visited.end())
            return visited[node];

        // Clone the current node
        Node* clone = new Node(node->val);
        visited[node] = clone;

        // Clone all the neighbors
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor, visited));
        }

        return clone;
    }
};
