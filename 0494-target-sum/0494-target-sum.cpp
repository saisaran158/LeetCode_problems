class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int x : nums) sum += x;
        int tar = sum + abs(target);
        if(tar % 2 != 0) return 0;
        int n = nums.size();
        int t = tar / 2;
        vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));
        for(int i = 0; i <= n; i++) dp[i][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <=t; j++){
                if(j < nums[i-1])
                dp[i][j] = dp[i - 1][j];
                else
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];

            }
        }
        return dp[n][t];
    }
};