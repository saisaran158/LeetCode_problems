class Solution {
public:
    int rec(int i, int& n, vector<int>& cost, vector<int>& dp){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];

        int costs = 1e9;
        for(int j = i + 1; j <= i + 3 && j <= n; j++){
            costs = min(costs, (cost[j - 1] + ((j - i) * (j - i))) + rec(j, n, cost, dp));
        }

        return dp[i] = costs;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n, -1);
        return rec(0, n, costs, dp);
    }
};