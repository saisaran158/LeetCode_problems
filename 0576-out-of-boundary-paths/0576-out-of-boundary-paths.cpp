class Solution {
public:
    int delr[4] = {-1, 0, 1, 0};
    int delc[4] = {0, 1, 0, -1};
    long long mod = 1e9 + 7;
    int recursion(int i, int j, int& m, int& n, int movesLeft, vector<vector<vector<int>>>& dp) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return 1;
        }
        if(dp[i][j][movesLeft] != -1) return dp[i][j][movesLeft];
         if (movesLeft == 0)
            return 0;

        long long ans = 0;
        for (int k = 0; k < 4; k++) {
            ans =
                (ans + recursion(i + delr[k], j + delc[k], m, n, movesLeft - 1, dp)) % mod;
        }

        return dp[i][j][movesLeft] = ans % mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return recursion(startRow, startColumn, m, n, maxMove, dp);
    }
};