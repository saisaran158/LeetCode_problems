class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 0;
        int l = 0;
        int r = 0;
        for(int i = 1; i <= n; i++){
            l += s2[i-1];
            dp[0][i] = l;
        }
        for(int i = 1; i <= m; i++){
            r += s1[i-1];
            dp[i][0] = r;
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = min(s1[i - 1] + dp[i - 1][j], s2[j- 1] +dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};