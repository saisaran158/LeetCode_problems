class Solution {
public:
    vector<vector<vector<int>>> dp;

    int solve(int r1, int c1, int r2, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int c2 = r1 + c1 - r2;
        if (r1 >= grid.size() || r2 >= grid.size() || c1 >= grid[0].size() ||
            c2 >= grid[0].size()) {
            return -1e9;
        }

        if (grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return -1e9;
        }
        if (dp[r1][c1][r2] != -1e9)
            return dp[r1][c1][r2];
        if (r1 == m - 1 && c1 == n - 1) {
            return dp[r1][c1][r2] = grid[r1][c1];
        }
        int ans = 0;

        if (r1 == r2 && c1 == c2) {
            ans += grid[r1][c1];
        } else {
            ans += grid[r1][c1] + grid[r2][c2];
        }

        int cherries =
            max({solve(r1 + 1, c1, r2 + 1, grid), solve(r1 + 1, c1, r2, grid),
                 solve(r1, c1 + 1, r2 + 1, grid), solve(r1, c1 + 1, r2, grid)});

        return dp[r1][c1][r2] = ans + cherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        dp.resize(m, vector<vector<int>>(n, vector<int>(m, -1e9)));
        return max(0, solve(0, 0, 0, grid));
    }
};