class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m + 1, vector<int>(n + 1));
        for(int i = 0; i < m; i++){
            dp[i][0] = 0;
        }
        for(int i = 0; i < n; i++){
            dp[0][i] = 0;
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = matrix[i - 1][j - 1];
            }
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                int m = min({dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j]});
                if(dp[i][j] == 1)
                dp[i][j] = m >= 1 ? m + 1 : dp[i][j];
            }
        }
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                cout << dp[i][j] <<" ";
            }
            cout << endl;
        }
        int c = 0;
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                c += dp[i][j];
            }
        }
        return c;
    }
};