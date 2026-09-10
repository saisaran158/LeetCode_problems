class Solution {
public:
    long long recursion(int i, int& n, vector<vector<int>>& questions, vector<long long>& dp){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        long long solved = questions[i][0] + recursion(i + questions[i][1] + 1, n, questions, dp);

        long long skipped = recursion(i + 1, n, questions, dp);

        return dp[i] = max(solved, skipped);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long>dp(n, -1);
        return recursion(0, n, questions, dp);
    }
};