class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n,0));
        int ans = 0;
        for (int k = 0; k < n ; k++) {
            for(int i = 0, j = i + k; j < n; i++ , j++){
                if(i == j) dp[i][j] = 1;
                else if(k == 1){
                    if(s[i] == s[j]){
                        dp[i][j] = 2;
                    }
                }
                else if(s[i] == s[j] && dp[i+1][j-1] != 0){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                if(dp[i][j] > 0) ans++;
            }
        }
        return ans;
    }
};