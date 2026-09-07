class Solution {
public:
    int m, n;
    int delr[2] = {0, 1};
    int delc[2] = {1, 0};
    bool recursion(int i, int j, int open, int close,
                   vector<vector<char>>& grid,
                   vector<vector<vector<int>>>& dp) {
        if (close > open)
            return false;
        if (dp[i][j][open - close] != -1)
            return dp[i][j][open - close];
        if (i == m - 1 && j == n - 1 && open - close == 0)
            return true;
        bool ans = false;
        for (int k = 0; k < 2; k++) {
            int nr = i + delr[k];
            int nc = j + delc[k];
            int onew = open;
            int cnew = close;
            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                if (grid[nr][nc] == '(') {
                    onew++;
                } else {
                    cnew++;
                }
                ans = ans || recursion(nr, nc, onew, cnew, grid, dp);
            }
        }

        return dp[i][j][open - close] = ans;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(m + n, -1)));
        int open = 0, close = 0;
        if (grid[0][0] == '(')
            open++;
        else
            close++;
        return recursion(0, 0, open, close, grid, dp);
    }
};