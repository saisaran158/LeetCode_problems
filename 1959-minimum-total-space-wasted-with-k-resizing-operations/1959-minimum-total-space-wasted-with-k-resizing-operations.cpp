class Solution {
public:
    int rec(int i, int n, vector<int>& nums, int k, vector<int>& prefix, vector<vector<int>>& dp){
        if(i >= nums.size()) return 0;
        if(k == 0){
            int m = nums[i];
            for(int j = i; j <= n; j++){
                m = max(m, nums[j]);
            }
            if(i == 0){
                return (m * (n - i + 1)) - (prefix[n]);
            }
            return (m * (n - i + 1)) - (prefix[n] - prefix[i - 1]);
        }
        if(dp[i][k] != -1) return dp[i][k];
        int waste = 1e9;
        int maxi = -1e9;
        for(int j = i; j <= n; j++){
            maxi = max(maxi, nums[j]);
            if(i != 0)
            waste = min(waste, (maxi * (j - i + 1) - (prefix[j] - prefix[i - 1])) + rec(j + 1, n, nums, k - 1, prefix, dp)); 
            else if(i == 0)
            waste = min(waste, (maxi * (j - i + 1) - (prefix[j])) + rec(j + 1, n, nums, k - 1, prefix, dp));
        }
        return dp[i][k] = waste;
    }
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>prefix(n);
        prefix[0] = nums[0];
        vector<vector<int>>dp(n, vector<int>(k + 1, -1));
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] + nums[i];
        }
        return rec(0, n - 1, nums, k, prefix, dp);
    }
};