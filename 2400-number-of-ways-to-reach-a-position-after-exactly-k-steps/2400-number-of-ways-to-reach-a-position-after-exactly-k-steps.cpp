class Solution {
public:
    int mod = 1e9 + 7;
    int rec(int start, int end, int k, vector<vector<int>>& dp, int f){
        if(start == end && k == 0){
            return 1;
        }
        if(k < 0) return 0;
        if(dp[start + f][k] != -1) return dp[start + f][k];

        int ways = 0;
        ways = (ways + rec(start + 1, end, k - 1, dp, f)) % mod;
        ways = (ways + rec(start - 1, end, k - 1, dp, f)) % mod;

        return dp[start + f][k] = ways;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>>dp(startPos + k+k + 1, vector<int>(k + 1, -1));
        return rec(startPos, endPos, k, dp, k);
    }
};