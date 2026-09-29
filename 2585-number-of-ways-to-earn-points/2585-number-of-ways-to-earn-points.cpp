class Solution {
public:
    int mod = 1e9 + 7;
    int rec(int i, int& n, int& target, int sum, vector<vector<int>>& types, vector<vector<int>>& dp){
        if(sum == target) return 1;
        if(sum > target) return 0;
        if(i >= n) return 0;
        if(dp[i][sum] != -1) return dp[i][sum];
        int ans = 0;
        int curr = 0;
        for(int j = 0; j < types[i][0]; j++){
            curr += types[i][1];
            ans = (ans + rec(i + 1, n, target, sum + curr, types, dp)) % mod;
        }
        ans = (ans + rec(i + 1, n, target, sum, types, dp)) % mod;
        return dp[i][sum] = ans % mod;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        vector<vector<int>>dp(n, vector<int>(target + 1, -1));
        return rec(0, n, target, 0, types, dp) % mod;
    }
};