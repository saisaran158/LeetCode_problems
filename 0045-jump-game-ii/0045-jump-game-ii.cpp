class Solution {
public:
    int solve(int i, int& n, vector<int>& nums, vector<int>& dp) {
        if (i >= n - 1) {
            return 0;
        }
        if (nums[i] == 0)
            return dp[i] = 1e9;
        if(dp[i] != -1) return dp[i];
        int ans = 1e9;
        for (int j = i + 1; j <= nums[i] + i && j < n; j++) {
            ans = min(ans, 1 + solve(j, n, nums, dp));
        }
        return dp[i] = ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        return solve(0, n, nums, dp);
    }
};