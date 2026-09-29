class Solution {
public:
    int rec(int i, int& n, vector<int>& startTime, vector<int>& endTime, vector<int>& profit, vector<int>& dp){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        ans = max(ans, rec(i + 1, n, startTime, endTime, profit, dp));

        ans = max(ans, profit[i] + rec(lower_bound(startTime.begin(), startTime.end(), endTime[i]) - startTime.begin(), n, startTime, endTime, profit, dp));

        return dp[i] = ans;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<tuple<int, int, int>>jobs;
        for(int i = 0; i < n; i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        for(int i = 0; i < jobs.size(); i++){
            auto[st, et, pt] = jobs[i];
            startTime[i] = st;
            endTime[i] = et;
            profit[i] = pt;
        }
        vector<int>dp(n + 1, -1);
        return rec(0, n, startTime, endTime, profit, dp);
    }
};