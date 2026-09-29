class Solution {
public:
    int rec(int i, int& n, int rem, vector<int>& cost, vector<int>& time, vector<vector<int>>& dp){
        if(rem <= 0) return 0;
        if(i >= n) return 1e9;
        if(dp[i][rem] != -1) return dp[i][rem];
        int take = cost[i] + rec(i + 1, n, rem - time[i] - 1, cost, time, dp);
        int skip = rec(i + 1, n, rem, cost, time, dp);

        return dp[i][rem] = min(take, skip);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>>dp(n, vector<int>(n + 1, -1));
        return rec(0, n, n, cost, time, dp);
    }
};