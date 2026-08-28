class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>dp(n, -1);
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(-target <= nums[i] - nums[prev] && nums[i] - nums[prev] <= target && 1 + dp[prev] > dp[i] && dp[prev] != -1){
                    dp[i] = 1 + dp[prev];
                }
            }
        }
        return dp[n - 1] == 0 ?-1 : dp[n - 1];
    }
};