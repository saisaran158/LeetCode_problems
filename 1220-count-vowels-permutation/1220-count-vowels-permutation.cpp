class Solution {
public:
    long long mod = 1e9 + 7;
    int rec(int prev, string& vowels, int n, vector<vector<int>>&dp){
        if(dp[prev + 1][n] != -1) return dp[prev + 1][n];
        if(n == 0) return 1;
        int ans = 0;
        for(int next = 0; next < 5; next++){
            if((prev == -1) || vowels[prev] == 'a' && vowels[next] == 'e'){
                ans = (ans + rec(next, vowels, n - 1, dp)) % mod;
            }
            else if((prev == -1) || vowels[prev] == 'e' && (vowels[next] == 'a' || vowels[next] == 'i')){
                ans = (ans + rec(next, vowels, n - 1, dp)) % mod;
            }
            else if((prev == -1) || vowels[prev] == 'i' && vowels[next] != 'i'){
                ans = (ans + rec(next, vowels, n - 1, dp)) % mod;
            }
            else if((prev == -1) || vowels[prev] == 'o' && (vowels[next] == 'i' || vowels[next] == 'u')){
                ans = (ans + rec(next, vowels, n - 1, dp)) % mod;
            }
            else if((prev == -1) || vowels[prev] == 'u' && vowels[next] == 'a'){
                ans = (ans + rec(next, vowels, n - 1, dp)) % mod;
            }
        }
        return dp[prev + 1][n] = ans;
    }
    int countVowelPermutation(int n) {
        string vowels = "aeiou";
        vector<vector<int>>dp(6, vector<int>(n + 1, -1));
        return rec(-1, vowels, n, dp);
    }
};