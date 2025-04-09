class Solution {
public:
    void dfs(int u, int parent, vector<int> adj[], vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<bool>& isArticulation, int& time) {
        visited[u] = true;
        disc[u] = low[u] = ++time;
        int children = 0;

        for (int v : adj[u]) {
            if (!visited[v]) {
                children++;
                dfs(v, u, adj, visited, disc, low, isArticulation, time);
                low[u] = min(low[u], low[v]);

                // Case 1: u is root and has two or more children
                if (parent == -1 && children > 1)
                    isArticulation[u] = true;

                // Case 2: u is not root and low[v] >= disc[u]
                if (parent != -1 && low[v] >= disc[u])
                    isArticulation[u] = true;
            } else if (v != parent) {
                // Back edge
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(V, false);
        vector<int> disc(V, -1), low(V, -1);
        vector<bool> isArticulation(V, false);
        int time = 0;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, -1, adj, visited, disc, low, isArticulation, time);
            }
        }

        vector<int> result;
        for (int i = 0; i < V; ++i) {
            if (isArticulation[i]) result.push_back(i);
        }

        if (result.empty()) return {-1};
        return result;
    }
};
