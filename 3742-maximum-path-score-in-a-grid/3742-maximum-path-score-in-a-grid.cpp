class Solution {
public:
    int delr[2] = {0, 1};
    int delc[2] = {1, 0};
    int rec(int r, int c, int& m, int& n, int k, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        if (r == m - 1 && c == n - 1) {
            return grid[r][c];
        }
        if(dp[r][c][k] != -1) return dp[r][c][k];
        int ans = INT_MIN;
        for (int i = 0; i < 2; i++) {
            int nr = r + delr[i];
            int nc = c + delc[i];
            int newk = k;
            if (nr >= 0 && nc >= 0 && nr < m && nc < n) {
                if (newk > 0) {
                    if(grid[nr][nc] == 1 || grid[nr][nc] == 2){
                        newk--;
                    }
                    ans = max(ans, grid[r][c] + rec(nr, nc, m, n, newk, grid, dp));
                }
                else if(grid[nr][nc] == 0){
                    ans = max(ans, grid[r][c] + rec(nr, nc, m, n, newk, grid, dp));
                }
            }
        }

        return dp[r][c][k] = ans;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        int ans = rec(0, 0, m, n, k, grid, dp);
        return ans < 0 ? -1 : ans ;
    }
};