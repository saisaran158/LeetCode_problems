class Solution {
public:
    int rec(int i, int n, vector<int>& nums, int k, int op1, int op2, vector<vector<vector<int>>>& dp) {
        if (i >= n)
            return 0;
        if(dp[i][op1][op2] != -1) return dp[i][op1][op2];
        int ans = 1e9;
        int ele = 0;
        if (nums[i] % 2 == 0) {
            ele = nums[i] / 2;
        } else if (nums[i] % 2 == 1) {
            ele = (nums[i] / 2) + 1;
        }
        if(op1 > 0)
        ans = min(ans, ele + rec(i + 1, n, nums, k, op1 - 1, op2, dp));

        if (op2 > 0 && nums[i] >= k && k >0) {
            ans = min(ans, nums[i] - k + rec(i + 1, n, nums, k, op1, op2 - 1, dp));
        }

        if (op2 > 0 && op1 > 0 && ele >= k && k > 0) {
            ans = min(ans, ele - k + rec(i + 1, n, nums, k, op1 - 1, op2 - 1, dp));
        }
        if (op2 > 0 && op1 > 0 && nums[i] >= k && k > 0) {
            int m = (nums[i] - k);
            int p = 0;
            if (m % 2 == 0)
                p = 0;
            else if (m % 2 == 1)
                p = 1;
            ans = min(ans, ((m / 2) + p) + rec(i + 1, n, nums, k, op1 - 1, op2 - 1, dp));
        }

        ans = min(ans, nums[i] + rec(i + 1, n, nums, k, op1, op2, dp));
        return dp[i][op1][op2] = ans;
    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(op1 + 1, vector<int>(op2 + 1, -1)));
        return rec(0, n, nums, k, op1, op2, dp);
    }
};