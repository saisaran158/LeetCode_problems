class Solution {
public:
    long long recursion(long long i, vector<int>& nums, unordered_map<int, long long>& mp, vector<long long>& dp){
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        long long ind = upper_bound(nums.begin(), nums.end(), nums[i] + 2) - nums.begin();
        // while(ind < nums.size() && nums[ind] <= nums[i] + 2){
        //     ind++;
        // }
        long long del = (nums[i] * mp[nums[i]]) + recursion(ind, nums, mp, dp);

        long long ddel = recursion(i + 1, nums, mp, dp);

        return dp[i] = max(del, ddel); 
    }
    long long maximumTotalDamage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, long long>mp;
        for(auto x : nums){
            mp[x]++;
        }
        long long n = nums.size();
        vector<long long>dp(n, -1);
        return recursion(0, nums, mp, dp);
    }
};