class Solution {
public:
    int rec(int i, vector<int>& dp){
        if(i == 0) return 1;
        if(dp[i] != -1) return dp[i];
        int cost = 1;
        for(int j = 1; j <= i; j++){
            cost = max(cost, j * rec(i - j, dp));
        }
        return dp[i] = cost;
    }
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        vector<int>dp(n + 1, -1);
        return rec(n, dp);
    }
};