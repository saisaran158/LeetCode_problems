class Solution {
public:
    int rec(int i, vector<int>& start, vector<int>& end, vector<int>& dp){
        if(i >= start.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        ans = max(ans, rec(i + 1, start, end, dp));
        ans = max(ans, 1 + rec(upper_bound(start.begin(), start.end(), end[i]) - start.begin(), start, end, dp));

        return dp[i] =ans;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<int>start;
        vector<int>end;
        vector<tuple<int, int>>tup;
        for(auto x : pairs){
            tup.push_back({x[0], x[1]});
        }
        sort(tup.begin(), tup.end());
        for(int i = 0; i < tup.size(); i++){
            auto[s, e] = tup[i];
            start.push_back(s);
            end.push_back(e);
        }
        vector<int>dp(start.size(), -1);
        return rec(0, start, end, dp);
    }
};