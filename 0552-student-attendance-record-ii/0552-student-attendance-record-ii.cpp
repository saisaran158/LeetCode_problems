class Solution {
public:
    int mod = 1e9 + 7;
    int rec(int i, int& n, int absent, int late, vector<vector<vector<int>>>& dp){
        if(absent >= 2 || late >= 3) return 0;
        if(i == n) return 1;
        if(dp[i][absent][late] != -1) return dp[i][absent][late];
        int ways = 0;
        ways = (ways + rec(i + 1, n, absent + 1, 0, dp)) % mod;
        ways = (ways + rec(i + 1, n, absent, late + 1, dp)) % mod;
        ways = (ways + rec(i + 1, n, absent, 0, dp)) % mod;

        return dp[i][absent][late] = ways;
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return rec(0, n, 0, 0, dp);
    }
};