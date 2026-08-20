class Solution {
public:
    int dp[70][70][70][70];
    int solve(int r1, int c1, int r2, int c2, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (r1 >= m || r2 >= m || c1 >= n || c2 >= n || c1 < 0 || c2 < 0)
            return -1e9;
        if (dp[r1][c1][r2][c2] != -1)
            return dp[r1][c1][r2][c2];
        if (r1 == m - 1 || r2 == m - 1) {
            if (c1 == c2)
                return dp[r1][c1][r2][c2] = grid[r1][c1];
            else
                return dp[r1][c1][r2][c2] = grid[r1][c1] + grid[r2][c2];
        }
        int ans = 0;
        if (r1 == r2 && c1 == c2)
            ans += grid[r1][c1];
        else {
            ans += grid[r1][c1] + grid[r2][c2];
        }

        int cherries = max({solve(r1 + 1, c1 - 1, r2 + 1, c2 - 1, grid),
                            solve(r1 + 1, c1, r2 + 1, c2, grid),
                            solve(r1 + 1, c1 + 1, r2 + 1, c2 + 1, grid),
                            solve(r1 + 1, c1 - 1, r2 + 1, c2, grid),
                            solve(r1 + 1, c1 - 1, r2 + 1, c2 + 1, grid),
                            solve(r1 + 1, c1, r2 + 1, c2 - 1, grid),
                            solve(r1 + 1, c1, r2 + 1, c2 + 1, grid),
                            solve(r1 + 1, c1 + 1, r2 + 1, c2 - 1, grid),
                            solve(r1 + 1, c1 + 1, r2 + 1, c2, grid)});

        return dp[r1][c1][r2][c2] = ans + cherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, n - 1, grid);
    }
};