class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(i < 0 || j >= matrix[0].size()) return INT_MAX;
        if(i == matrix.size() - 1 && j >= 0 && j < matrix[0].size()) return matrix[i][j];
        if(dp[i][j] != 1e9){
            return dp[i][j];
        }

        int l = solve(i + 1, j - 1, matrix, dp);
        int s = solve(i + 1, j, matrix, dp);
        int r = solve(i + 1, j + 1, matrix, dp);

        return dp[i][j] = matrix[i][j] + min(l, min(s, r));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1e9));
        int res = INT_MAX;
        for(int j = 0; j < matrix[0].size(); j++){
            res = min(res, solve(0, j, matrix, dp));
        }
        return res;
    }
};