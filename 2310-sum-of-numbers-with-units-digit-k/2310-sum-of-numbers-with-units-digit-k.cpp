class Solution {
public:
    int rec(int curr, int nums, int k, vector<int>& dp){
        // cout << curr << endl;
        if(curr == nums) return 0;
        if(curr > nums) return 1e9;
        if(dp[curr] != -1) return dp[curr];
        int len = 1e9;
        for(int j = 1; j <= nums; j++){
            if(j % 10 == k){
                // cout << j << endl;
                len = min(len, 1 + rec(curr + j, nums, k, dp));
            }
        }
        return dp[curr] = len;
    }
    int minimumNumbers(int num, int k) {
        vector<int>dp(num + 1, -1);
        int ans = rec(0, num, k, dp);
        if(ans >= 1e8) return -1;
        return ans;
    }
};