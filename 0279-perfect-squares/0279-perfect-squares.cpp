class Solution {
public:
    int recursion(int i, int n, vector<int>&res, vector<vector<int>>& dp){
        if(i >= res.size()) return 1e9;
        if(dp[i][n] != -1) return dp[i][n];
        if(n == 0) return 0;

        int take = 1e9;
        int ans = 1e9;
        if(res[i] <= n)
        take = 1 + recursion(i, n - res[i], res, dp);
        int dtake = recursion(i + 1, n, res, dp);
        ans = min(take, dtake);
        return dp[i][n] = ans;
    }
    int numSquares(int n) {
        vector<int>res;
        int i = 1;
        while(i * i <= n){
            if(i * i == n) return 1;
            res.push_back(i * i);
            i++;
        }
        int s = res.size();
        vector<vector<int>>dp(s + 1, vector<int>(n + 1, -1));
        return recursion(0, n, res, dp);
    }
};