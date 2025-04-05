class Solution {
public:
    int n, m;

    // Directions for 8 neighbors
    vector<pair<int, int>> directions = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1},
        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
    };

    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        visited[i][j] = true;

        for (int k = 0; k < directions.size(); ++k) {
            int ni = i + directions[k].first;
            int nj = j + directions[k].second;

            if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                grid[ni][nj] == 'L' && !visited[ni][nj]) {
                dfs(ni, nj, grid, visited);
            }
        }
    }

    int countIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        n = grid.size();
        m = grid[0].size();
        int count = 0;

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'L' && !visited[i][j]) {
                    dfs(i, j, grid, visited);
                    count++;
                }
            }
        }

        return count;
    }
};
