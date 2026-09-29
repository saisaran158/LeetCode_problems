class Solution {
public:
    int rec(int i, int& n, vector<int>& scores, int prev, vector<vector<int>>& dp){
        if(i >= n) return 0;
        if(dp[i][prev + 1] != -1) return dp[i][prev + 1];
        int ans = 0;
        if(prev == -1 || scores[prev] <= scores[i]){
            ans = max(ans, scores[i] + rec(i + 1, n, scores, i, dp));
        }

        ans = max(ans, rec(i + 1, n, scores, prev, dp));

        return dp[i][prev + 1] = ans;
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<tuple<int, int>>tup;
        int n = scores.size();
        for(int i = 0; i < n; i++){
            tup.push_back({ages[i], scores[i]});
        }
        sort(tup.begin(), tup.end());
        for(int i = 0; i < n; i++){
            auto[ag, sc] = tup[i];
            ages[i] = ag;
            scores[i] = sc;
        }
        vector<vector<int>>dp(n + 1, vector<int>(n + 2, -1));
        return rec(0, n, scores, -1, dp);
    }
};