class Solution {
public:
     int rec(int i, vector<int>& startTime, vector<int>& endTime, vector<int>& profit, vector<int>& dp){
        if(i >= startTime.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        ans = max(ans, rec(i + 1, startTime, endTime, profit, dp));

        ans = max(ans, profit[i] + rec(upper_bound(startTime.begin(), startTime.end(), endTime[i]) - startTime.begin(), startTime, endTime, profit, dp));

        return dp[i] = ans;
    }
    int maximizeTheProfit(int n, vector<vector<int>>& events) {
        vector<tuple<int, int, int>>ways;
        for(auto x : events){
            ways.push_back({x[0], x[1], x[2]});
        }
        sort(ways.begin(), ways.end());
        vector<int>start;
        vector<int>end;
        vector<int>value;
        for(int i = 0; i < ways.size(); i++){
            auto[st, et, val] = ways[i];
            start.push_back(st);
            end.push_back(et);
            value.push_back(val);
        }
        vector<int>dp(start.size(), -1);
        return rec(0, start, end, value, dp);
    }
};