class Solution {
public:
    int rec(int i, int& full, vector<string>& strs, int& m, int& n, int mc, int nc, vector<vector<vector<int>>>& dp){
        if(i >= full) return 0;
        if(dp[i][mc][nc] != -1) return dp[i][mc][nc];

        int len = 0;
        len = max(len, rec(i + 1, full, strs, m, n, mc, nc, dp));
        int c1 = 0, c2 = 0;
        for(char a : strs[i]){
            if(a == '0') c1++;
            else c2++;
        }

        if(mc + c1 <= m && nc + c2 <= n){
            len = max(len, 1 + rec(i + 1, full, strs, m, n, mc + c1, nc + c2, dp));
        }

        return dp[i][mc][nc] = len;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int full = strs.size();
        vector<vector<vector<int>>>dp(full, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return rec(0, full, strs, m, n, 0, 0, dp);
    }
};