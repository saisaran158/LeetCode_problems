class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int x : nums) sum +=x;
        if(sum % 2 == 1)return false;
        int target = sum /2;
        vector<vector<bool>>dp(n + 1, vector<bool>(target + 1, 0));
        for(int i = 0; i <= n; i++) dp[i][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= target; j++){
                if(j < nums[i-1])
                dp[i][j] = dp[i-1][j];
                else
                dp[i][j] = dp[i-1][j] + dp[i - 1][j - nums[i - 1]];
            }
        }
        return dp[n][target];
    }
};