class Solution {
public:
    int mod = 1e9 + 7;
    int rec(int pos, int steps, int arrLen, vector<vector<int>>& dp){
        if(steps == 0 && pos == 0){
            return 1;
        }
        if(pos < 0) return 0;
        if(pos >= arrLen) return 0;
        if(steps < 0) return 0;
        if(dp[pos][steps] != -1) return dp[pos][steps];
        int ans = 0;
        ans = (ans + rec(pos + 1, steps - 1, arrLen, dp)) % mod;
        ans = (ans + rec(pos - 1, steps - 1, arrLen, dp)) % mod;
        ans = (ans + rec(pos, steps - 1, arrLen, dp)) % mod;

        return dp[pos][steps] = ans;
    }
    int numWays(int steps, int arrLen) {
        vector<vector<int>>dp(min(501, arrLen), vector<int>(steps + 1, -1));
        return rec(0, steps, arrLen, dp);
    }
};