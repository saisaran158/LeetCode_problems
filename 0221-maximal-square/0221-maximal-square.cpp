class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = matrix[i - 1][j - 1] - '0';
            }
        }
        int maxLen = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                int m = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]});
                if(dp[i][j] != 0){
                    dp[i][j] = m >= 1 ? m + 1 : dp[i][j];
                    maxLen = max(maxLen, dp[i][j] * dp[i][j]);
                }
            }
        }
        return maxLen;
    }
};