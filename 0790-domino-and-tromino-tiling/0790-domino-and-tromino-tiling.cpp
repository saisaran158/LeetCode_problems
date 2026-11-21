class Solution {
public:
    int numTilings(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 5;
        int dp[n];
        int mod = 1e9 + 7;
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 5;
        for(int i = 3; i < n; i++){
            dp[i] = ((dp[i - 1] * 2) % mod + dp[i - 3]) % mod;
        }
        return dp[n - 1] % mod;
    }
};