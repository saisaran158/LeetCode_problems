class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        int dp[nums.size()-1];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size() - 1; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }
        int dp1[nums.size()];
        dp1[0] = 0;
        dp1[1] = nums[1];
        for(int i = 2; i < nums.size(); i++){
            dp1[i] = max(dp1[i - 1], nums[i] + dp1[i - 2]);
        }
        return max(dp[n-2], dp1[n-1]);
    }
};