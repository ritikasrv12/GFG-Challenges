class Solution {
  public:
    string findOrder(vector<string> &words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        unordered_set<char> uniqueChars;

        // Step 1: Initialize
        for (const string &word : words) {
            for (char c : word) {
                uniqueChars.insert(c);
                if (indegree.find(c) == indegree.end()) {
                    indegree[c] = 0;
                }
            }
        }

        // Step 2: Build graph
        for (int i = 0; i < words.size() - 1; ++i) {
            string w1 = words[i], w2 = words[i + 1];
            int len = min(w1.size(), w2.size());
            bool found = false;
            for (int j = 0; j < len; ++j) {
                if (w1[j] != w2[j]) {
                    if (!adj[w1[j]].count(w2[j])) {
                        adj[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    found = true;
                    break;
                }
            }
            if (!found && w1.size() > w2.size()) {
                return ""; // Invalid case
            }
        }

        // Step 3: Topological sort
        queue<char> q;
        for (auto &entry : indegree) {
            if (entry.second == 0)
                q.push(entry.first);
        }

        string result;
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            result += c;

            for (char neighbor : adj[c]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        return result.size() == uniqueChars.size() ? result : "";
    }
};
