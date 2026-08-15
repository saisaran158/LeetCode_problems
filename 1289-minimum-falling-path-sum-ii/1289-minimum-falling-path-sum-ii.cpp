class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid){
        if(i < 0 || j >= grid[0].size()) return INT_MAX;
        if(i == grid.size() - 1 && j >=0 && j < grid[0].size()) return grid[i][j];
        if(dp[i][j] != 1e9) return dp[i][j];

        int ans = INT_MAX;
        for(int k = 0; k < grid[0].size(); k++){
            if(j == k) continue;
            ans = min(ans, solve(i + 1, k, dp, grid));
        }
        
        return dp[i][j] = grid[i][j] + ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int res = INT_MAX;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, 1e9));
        for(int j = 0; j < grid[0].size(); j++){
            res = min(res, solve(0, j, dp, grid));
        }
        return res;
    }
};