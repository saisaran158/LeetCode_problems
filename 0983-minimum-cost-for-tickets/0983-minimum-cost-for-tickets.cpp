class Solution {
public:
    int recursion(int i, int& n, vector<int>& days, vector<int>& cost, vector<int>&dp) {
        if (i >= n)
            return 0;
        if(dp[i] != -1) return dp[i];
        int ind = i;
        while (ind < n && days[ind] < days[i] + 1) {
            ind++;
        }
        int first = cost[0] + recursion(ind, n, days, cost, dp);
        ind = i;
        while (ind < n && days[ind] < days[i] + 7) {
            ind++;
        }
        int second = cost[1] + recursion(ind, n, days, cost, dp);
        ind = i;
        while (ind < n && days[ind] < days[i] + 30) {
            ind++;
        }
        int third = cost[2] + recursion(ind, n, days, cost, dp);

        return dp[i] = min({first, second, third});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n, -1);
        return recursion(0, n, days, costs, dp);
    }
};