class Solution {
public:
    int rec(int i, int& n, vector<int>& jobs, int d, vector<vector<int>>&dp){
        if(i >= n && d == 0) return 0;
        if(i < n && d == 0) return 1e9;
        if(i >= n && d > 0) return 1e9;
        if(dp[i][d] != -1) return dp[i][d];
        int currMax = 0;
        int ans = 1e9;
        for(int j = i; j < n; j++){
            currMax = max(currMax, jobs[j]);
            ans = min(ans, currMax + rec(j + 1, n, jobs, d - 1, dp));
        }

        return dp[i][d] = ans;
    }
    int minDifficulty(vector<int>& jobs, int d) {
        int n = jobs.size();
        vector<vector<int>>dp(n + 1, vector<int>(d + 1, -1));
        int ans = rec(0, n, jobs, d, dp);
        if(ans == 1e9) return -1;
        return ans;
    }
};