class Solution {
public:
    int dp[1001][1002][2];
    int rec(int i, int& n, vector<int>& nums, int prev, int flag){
        if(i >= n) return 0;
        if(dp[i][prev + 1][flag] != -1) return dp[i][prev + 1][flag];
        int len = 0;
        if(prev == -1){
            len = max(len, 1 + rec(i + 1, n, nums, i, 0));
            len = max(len, 1 + rec(i + 1, n, nums, i, 1));
        }
        if(prev != -1 && nums[prev] < nums[i] && flag == 0){
            len = max(len, 1 + rec(i + 1, n, nums, i, 1));
        }
        if(prev != -1 && nums[prev] > nums[i] && flag == 1){
            len = max(len, 1 + rec(i + 1, n, nums, i, 0));
        }
        len = max(len, rec(i + 1, n, nums, prev, flag));

        return dp[i][prev + 1][flag] = len;
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return rec(0, n, nums, -1, 0);
    }
};