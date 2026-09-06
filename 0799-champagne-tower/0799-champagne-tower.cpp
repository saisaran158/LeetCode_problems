class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>dp(101, vector<double>(101));
        dp[0][0] = poured;
        for(int i = 0; i < 100; i++){
            for(int j = 0; j <= i; j++){
                double curr = dp[i][j];
                if(curr > 1){
                    dp[i + 1][j] += (curr - 1) / 2.0;
                    dp[i + 1][j + 1] += (curr - 1) / 2.0;
                }
            }
        }
        return dp[query_row][query_glass] > 1.0 ? 1.0 : dp[query_row][query_glass];
    }
};