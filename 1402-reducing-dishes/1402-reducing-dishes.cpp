class Solution {
public:
    int rec(int i, int& n, int prepared, vector<int>& satisfaction, vector<vector<int>>& dp){
        if(i >= n) return 0;
        if(dp[i][prepared] != -1) return dp[i][prepared];
        int take = (satisfaction[i] * prepared) + rec(i + 1, n, prepared + 1, satisfaction, dp);
        int nontake = rec(i + 1, n, prepared, satisfaction, dp);

        return dp[i][prepared] = max(take, nontake);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
        return rec(0, n, 1, satisfaction, dp);
    }
};