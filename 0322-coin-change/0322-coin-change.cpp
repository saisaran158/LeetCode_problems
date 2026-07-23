class Solution {
public:
    int coinChange(vector<int>& coins, int capacity) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
        for(int i =1; i<=capacity; i++){
            dp[0][i] = 1e9;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= capacity; j++){
                if(j < coins[i - 1]){
                    dp[i][j] = dp[i - 1][j];
                }
                else{
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
                }
            }
        }
        return dp[n][capacity] != 1e9 ? dp[n][capacity]: -1;
    }
};