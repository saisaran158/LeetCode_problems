class Solution {
public:
    int solve(int ind, int buy, int& n, int trans, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(ind == n) return 0;
        if(trans == 0) return 0;
        if(dp[ind][buy][trans] != -1) return dp[ind][buy][trans];
        int profit = 0;
        if(buy){
            profit = max( -prices[ind] + solve(ind + 1, 0, n, trans, prices, dp), solve(ind + 1, 1, n, trans, prices, dp));
        }
        else{
            profit = max(prices[ind] + solve(ind + 1, 1, n, trans - 1, prices, dp), solve(ind + 1, 0, n, trans, prices, dp)); 
        }

        return dp[ind][buy][trans] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 1, n, 2, prices, dp);
    }
};