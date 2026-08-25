class Solution {
public:
    bool palin(int i, int j, string& s, vector<vector<int>>&dp1) {

        if (i >= j)
            return true;

        if (dp1[i][j] != -1)
            return dp1[i][j];

        if (s[i] != s[j])
            return dp1[i][j] = false;

        return dp1[i][j] = palin(i + 1, j - 1, s, dp1);
    }
    int solve(int i, int& n, string& s, int& k, vector<int>& dp,
              vector<vector<int>>& dp1) {
        if (i == n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int maxStep = -1e9;
        for (int j = i; j < n; j++) {
            if (j - i + 1 >= k && palin(i, j, s, dp1)) {
                int cost = 1 + solve(j + 1, n, s, k, dp, dp1);
                maxStep = max(maxStep, cost);
            }
        }
        maxStep = max(maxStep, solve(i + 1, n, s, k, dp, dp1));
        return dp[i] = maxStep;
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(n, -1);
        vector<vector<int>> dp1(n, vector<int>(n, -1));
        return solve(0, n, s, k, dp, dp1);
    }
};