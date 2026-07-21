class Solution {
public:
    int dpCalculate(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
        if(i < 0 || j < 0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s1[i] == s2[j])
        return dp[i][j] = 1 + dpCalculate(i-1, j-1, s1, s2, dp);
        return dp[i][j] = max(dpCalculate(i-1, j, s1, s2, dp), dpCalculate(i, j-1, s1, s2, dp));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(), s2.end());
        vector<vector<int>>dp(n, vector<int>(n, -1));
        dpCalculate(n-1, n-1, s, s2, dp);
        return dp[n-1][n-1];
    }
};