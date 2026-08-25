class Solution {
public:
    int palin(string&s, int l, int r){
        int c = 0;
        while(l < r){
            if(s[l] != s[r])c++;
            l++;
            r--;
        }
        return c;
    }
    int solve(int i, int& n, string& s, int k, vector<vector<int>>&dp){
        if(k == 0 && i == n) return 0;
        if(k == 0) return 1e9;
        if(dp[i][k] != -1) return dp[i][k];
        int minStep = 1e9;
        for(int j = i; j < n; j++){
            int cost = palin(s, i, j);
            minStep = min(minStep, cost + solve(j + 1, n, s, k-1, dp));
        }
        return dp[i][k] = minStep;
    }
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>>dp(n + 1, vector<int>(k + 1, -1));
        return solve(0, n, s, k, dp);
    }
};