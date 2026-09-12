class Solution {
public:
    long long mod = 1e9 + 7;
    int rec(int prev, int conc, int n, vector<int>& rollMax, vector<vector<vector<int>>>&dp){
        if(n == 1) return 1;
        if(dp[prev][conc][n] != -1) return dp[prev][conc][n];
        int ans = 0;
        for(int next = 1; next <= 6; next++){
            if(prev == next){
                if(conc + 1 <= rollMax[next - 1]){
                    ans = (ans + rec(next, conc + 1, n - 1, rollMax, dp)) % mod;
                }
            }
            else{
                ans = (ans + rec(next, 1, n - 1, rollMax, dp)) % mod;
            }   
        }
        return dp[prev][conc][n] = ans;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        int ans = 0;
        int up = *max_element(rollMax.begin(), rollMax.end());
        vector<vector<vector<int>>>dp(7, vector<vector<int>>(up + 1, vector<int>(n + 1, -1)));
        for(int i = 1; i <= 6; i++){
            ans = (ans + rec(i, 1, n, rollMax, dp)) % mod;
        }
        return ans;
    }
};