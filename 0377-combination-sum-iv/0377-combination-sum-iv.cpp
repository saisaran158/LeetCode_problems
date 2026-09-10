class Solution {
public:
    int recursion(vector<int>& nums, int target, vector<int>& dp){
        if(dp[target] != -1) return dp[target];
        if(target == 0) return 1;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= target)
            ans = ans + recursion(nums, target - nums[i], dp);
        }
        return dp[target] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>dp(target + 1, -1);
        return recursion(nums, target, dp);
    }
};