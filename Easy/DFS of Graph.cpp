class Solution {
  public:
    void dfsHelper(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result) {
        // Mark the current node as visited and add it to the result
        visited[node] = true;
        result.push_back(node);
        
        // Traverse all adjacent nodes in the given order
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, adj, visited, result);
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> result;
        int n = adj.size();
        vector<bool> visited(n, false);
        
        // Start DFS from node 0
        dfsHelper(0, adj, visited, result);
        
        return result;
        
    }
};
