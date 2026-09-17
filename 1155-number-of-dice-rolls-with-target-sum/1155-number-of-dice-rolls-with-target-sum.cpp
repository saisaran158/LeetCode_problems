class Solution {
public:
    int mod = 1e9 + 7;
    long long rec(int n, int k, int target, int sum, vector<vector<long long>>& dp){
        if(sum > target){
            return 0;
        }
        if(sum == target && n == 0){
            return 1;
        }
        if(n == 0){
            return 0;
        }
        if(dp[n][sum] != -1) return dp[n][sum];
        long long ways = 0;
        for(int j = 1; j <= k; j++){
            ways = (ways + (rec(n - 1, k, target, sum + j, dp)) % mod) % mod;
        }
        return dp[n][sum] = ways % mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>>dp(n + 1, vector<long long>(target + 1, -1));
        return rec(n, k, target, 0, dp) % mod;
    }
};