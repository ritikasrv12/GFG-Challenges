class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        int m = s1.length(), n = s2.length();
        
        // Create a DP table with dimensions (m+1) x (n+1)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        // Initialize the base cases
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;  // Need i deletions to convert s1[0..i] to an empty string
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;  // Need j insertions to convert an empty string to s2[0..j]
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];  // No operation needed if characters match
                } else {
                    dp[i][j] = min({dp[i - 1][j - 1],  // Replace
                                    dp[i - 1][j],      // Remove
                                    dp[i][j - 1]}) + 1;  // Insert
                }
            }
        }
        
        // The result is stored in dp[m][n]
        return dp[m][n];
    }
};
