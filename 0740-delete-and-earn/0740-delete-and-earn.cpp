class Solution {
public:
    int recursion(int i, vector<int>& nums, unordered_map<int, int>& mp, vector<int>& dp){
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int ind = i;
        while(ind < nums.size() && nums[ind] <= nums[i] + 1){
            ind++;
        }
        int del = (nums[i] * mp[nums[i]]) + recursion(ind, nums, mp, dp);

        int ddel = recursion(i + 1, nums, mp, dp);

        return dp[i] = max(del, ddel); 
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int>mp;
        for(auto x : nums){
            mp[x]++;
        }
        int n = nums.size();
        vector<int>dp(n, -1);
        return recursion(0, nums, mp, dp);
    }
};