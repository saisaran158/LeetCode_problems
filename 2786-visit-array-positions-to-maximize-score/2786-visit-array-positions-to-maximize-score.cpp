class Solution {
public:
    long long rec(int i, int& n, bool parity, vector<int>& nums, int x, vector<vector<long long>>& dp){
        if(i >= n) return 0;
        if(dp[i][parity] != -1) return dp[i][parity];

        long long nontake = rec(i + 1, n, parity, nums, x, dp);


        int currParity = nums[i] % 2;
        long long take = 0;
        if(parity != currParity){
            take = nums[i] + rec(i + 1, n, currParity, nums, x, dp) - x;
        }
        else if(parity == currParity){
            take = nums[i] + rec(i + 1, n, parity, nums, x, dp);
        }
        return dp[i][parity] = max(take, nontake);
    }
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        bool parity = nums[0] % 2;
        vector<vector<long long>>dp(n, vector<long long>(2, -1));
        return rec(1, n, parity, nums, x, dp) + nums[0];
    }
};