class Solution {
public:
    long long rec(int i, int& n, vector<int>& start, vector<int>& end, vector<int>& tip, vector<long long>& dp){
        if(i >= start.size()) return 0;
        if(dp[i] != -1) return dp[i];
        long long ans = 0;
        ans = max(ans, rec(i + 1, n, start, end, tip, dp));

        ans = max(ans, (end[i] - start[i] + tip[i]) + rec(lower_bound(start.begin(), start.end(), end[i]) - start.begin(), n, start, end, tip, dp));

        return dp[i] = ans;
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<tuple<int, int, int>>ways;
        int r = rides.size();
        for(auto x : rides){
            ways.push_back({x[0], x[1], x[2]});
        }
        sort(ways.begin(), ways.end());
        vector<int>start;
        vector<int>end;
        vector<int>tip;
        vector<long long>dp(r + 1, -1);
        for(int i = 0; i < r; i++){
            auto[st, et, tp] = ways[i];
            start.push_back(st);
            end.push_back(et);
            tip.push_back(tp);
        }
        return rec(0, n, start, end, tip, dp);
    }
};