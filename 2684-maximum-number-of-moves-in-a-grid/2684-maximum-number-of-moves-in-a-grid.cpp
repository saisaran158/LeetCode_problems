class Solution {
public:
    int delr[3] = {-1, 0, 1};
    int delc[3] = {1, 1, 1};
    int rec(int i, int j, vector<vector<int>>& grid, int& m, int& n, vector<vector<int>>& dp){
        if(dp[i][j] != -1) return dp[i][j];
        int moves = 0;
        for(int k = 0; k < 3; k++){
            int nr = i + delr[k];
            int nc = j + delc[k];
            if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid[i][j] < grid[nr][nc]){
                moves = max(moves, 1 + rec(nr, nc, grid, m, n, dp));
            }
        }
        return dp[i][j] = moves;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        for(int i = 0; i < m; i++){
            ans = max(ans, rec(i, 0, grid, m, n, dp));
        }
        return ans;
    }
};