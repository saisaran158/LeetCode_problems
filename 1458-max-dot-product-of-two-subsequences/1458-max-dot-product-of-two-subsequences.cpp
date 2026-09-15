class Solution {
public: 
    int rec(int i, int j, int& m, int& n, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp){
        if(i >= m || j >= n) return -1e9;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = -1e9;
        ans = max(ans, nums1[i] * nums2[j] + max(0, rec(i + 1, j + 1, m, n, nums1, nums2, dp)));
        ans = max(ans, rec(i, j + 1, m, n, nums1, nums2, dp));
        ans = max(ans, rec(i + 1, j, m, n, nums1, nums2, dp));
        return dp[i][j] = ans;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return rec(0, 0, m, n, nums1, nums2, dp);
    }
};