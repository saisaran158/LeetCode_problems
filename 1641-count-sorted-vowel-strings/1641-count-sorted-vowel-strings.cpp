class Solution {
public:
    long long rec(int i, string& vowels, int n, vector<vector<long long>>& dp){
        if(n == 1) return 1;
        if(i == 5) return 0;
        if(dp[i][n] != -1) return dp[i][n];
        long long ans = 0;
        for(int j = i; j < 5; j++){
            ans += rec(j, vowels, n - 1, dp);
        }
        return dp[i][n] = ans;
    }
    int countVowelStrings(int n) {
        long long ans = 0;
        string vowels = "aeiou";
        vector<vector<long long>>dp(5, vector<long long>(n + 1, -1));
        for(int i = 0; i < 5; i++){
            ans += rec(i, vowels, n, dp);
        }   
        return ans;
    }
};