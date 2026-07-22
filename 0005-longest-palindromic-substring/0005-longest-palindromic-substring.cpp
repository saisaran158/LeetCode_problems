class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans="";
        int maxlen = 0;
        vector<vector<int>>dp(n, vector<int>(n,0));
        for (int k = 0; k < n ; k++) {
            for(int i = 0, j = i + k; j < n; i++ , j++){
                if(i == j) dp[i][j] = 1;
                else if(k == 1 && s[i] == s[j]){
                    dp[i][j] = 2;
                }
                else if(s[i] == s[j] && dp[i+1][j-1] != 0){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                if(dp[i][j] != 0){
                    if(j - i + 1 > maxlen){
                        maxlen = j - i + 1;
                        ans = s.substr(i, maxlen);
                    }
                }
            }
        }
        return ans;
    }
};