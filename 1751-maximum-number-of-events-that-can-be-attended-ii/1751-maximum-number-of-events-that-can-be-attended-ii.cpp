class Solution {
public:
    int rec(int i, int c, vector<int>& start, vector<int>& end, vector<int>& value, vector<vector<int>>& dp, int k){
        if(i >= start.size()) return 0;
        if(c == k) return 0;
        if(dp[i][c] != -1) return dp[i][c];
        int ans = 0;
        ans = max(ans, rec(i + 1, c, start, end, value, dp, k));

        ans = max(ans, value[i] + rec(upper_bound(start.begin(), start.end(), end[i]) - start.begin(), c + 1, start, end, value, dp, k));

        return dp[i][c] = ans;
    }
    int maxValue(vector<vector<int>>& events, int k) {
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
        vector<vector<int>>dp(start.size(), vector<int>(k, -1));
        return rec(0, 0, start, end, value, dp, k);
    }
};