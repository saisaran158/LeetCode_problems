class Solution {
public:
    int recursion(int ind, int buy, int& n, vector<int>& prices, int fee, vector<vector<int>>& dp){
        if(ind == n) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int profit = 0;
        if(buy){
            profit = max(-prices[ind] + recursion(ind + 1, 0, n, prices, fee, dp), recursion(ind + 1, 1, n, prices, fee, dp));
        }
        else{
            profit = max(prices[ind] - fee + recursion(ind + 1, 1, n, prices, fee, dp), recursion(ind + 1, 0, n, prices, fee, dp));
        }

        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return recursion(0, 1, n, prices, fee, dp);
    }
};