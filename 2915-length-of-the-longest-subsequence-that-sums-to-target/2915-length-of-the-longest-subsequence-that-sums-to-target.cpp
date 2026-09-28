class Solution {
public:
    int rec(int i, int& n, vector<int>& nums, int& target, int sum, vector<vector<int>>& dp){
        if(sum == target){
            return 0;
        }
        if(i >= n || sum > target) return -1e9;
        if(dp[i][sum] != -1) return dp[i][sum];
        int len = INT_MIN;
        if(nums[i] <= target)
        len = max(len, 1 + rec(i + 1, n, nums, target, sum + nums[i], dp));

        len = max(len, rec(i + 1, n, nums, target, sum, dp));

        return dp[i][sum] = len;
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(target, -1));
        int ans = rec(0, n, nums, target, 0, dp);
        if(ans < 0) return -1;
        return ans;
    }
};