class Solution {
public:
    int m, n;
    int rec(int i, int j, int ind, vector<int>& nums, vector<int>& multipliers, int &m, int& n, vector<vector<int>>& dp){
        if(i >= m) return 0;
        if(j < 0) return 0;
        if(ind >= n) return 0;
        if(dp[i][ind] != -1) return dp[i][ind];
        int left = nums[i] * multipliers[ind] + rec(i + 1, j, ind + 1, nums, multipliers, m, n, dp);

        int right = nums[j] * multipliers[ind] + rec(i, j - 1, ind + 1, nums, multipliers, m, n, dp);

        return dp[i][ind] = max(left, right);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        m = nums.size();
        n = multipliers.size();
        vector<vector<int>>dp(m, vector<int>(n + 1, -1));
        return rec(0, m - 1, 0, nums, multipliers, m, n, dp);
    }
};