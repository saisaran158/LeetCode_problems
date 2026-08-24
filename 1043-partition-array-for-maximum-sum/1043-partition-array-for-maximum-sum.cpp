class Solution {
public:
    int solve(int i, int& k, int& n, vector<int>& arr, vector<int>& dp){
        if(i == n){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int maxc = INT_MIN;
        int maxe = INT_MIN;
        for(int j = i; j < n && j < i + k; j++){
            maxe = max(arr[j], maxe);
            int cost = maxe * (j - i + 1);
            cost += solve(j + 1, k, n, arr, dp);

            maxc = max(cost, maxc);
        }
        return dp[i] = maxc;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n, -1);
        return solve(0, k, n, arr, dp);
    }
};