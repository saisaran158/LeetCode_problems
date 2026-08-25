class Solution {
public:
    int solve(int l, int r, vector<int>& cuts, int i, int j, vector<vector<int>>&dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int minCost = INT_MAX;
        for(int k = i ; k <= j; k++){
            int cost = r - l + solve(l, cuts[k], cuts, i, k - 1, dp) + solve(cuts[k], r, cuts, k + 1, j, dp);
            minCost = min(minCost, cost);
        }
        return dp[i][j] = minCost;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>>dp(m, vector<int>(m, -1));
        return solve(0, n, cuts, 0, cuts.size() - 1, dp);
    }
};