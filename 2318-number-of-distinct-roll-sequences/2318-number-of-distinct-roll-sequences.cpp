class Solution {
public:
    int mod = 1e9 + 7;
    int rec(int i, int n, int a, int b, vector<vector<vector<int>>>& dp){
        if(i == n) return 1;
        if(dp[i][a + 1][b + 1] != -1) return dp[i][a + 1][b + 1];
        int ans = 0;
        for(int k = 1; k <= 6; k++){
            if((b == -1 || (gcd(b, k) == 1 && b != k)) && a != k){
                ans = (ans + rec(i + 1, n, b, k, dp)) % mod;
            }
        }

        return dp[i][a + 1][b + 1] = ans;
    }
    int distinctSequences(int n) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(8, vector<int>(8, -1)));
        return rec(0, n, -1, -1, dp);
    }
};