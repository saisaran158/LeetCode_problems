class Solution {
public:
    long long mod = 1e9 + 7;
    int solve(int i, int j, int& m, int& n, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(dp[i][j] != -1) return dp[i][j] % mod;

        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};
        int ans = 1;
        for (int k = 0; k < 4; k++) {
            int nr = i + delr[k];
            int nc = j + delc[k];

            if (nr >= 0 && nc >= 0 && nr < m && nc < n) {
                if (matrix[nr][nc] > matrix[i][j]) {
                    ans = (ans + (solve(nr, nc, m, n, matrix, dp)) % mod) % mod;
                }
            }
        }

        return dp[i][j] = ans % mod;
    }
    int countPaths(vector<vector<int>>& matrix) {
        int res = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = (res+ (solve(i, j, m, n, matrix, dp)) % mod) % mod;
            }
        }
        return res % mod;
    }
};