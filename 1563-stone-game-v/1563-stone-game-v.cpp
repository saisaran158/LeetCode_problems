class Solution {
public:
    int rec(int i, int j, int total, vector<int>& stoneValue, int& n, vector<vector<int>>& dp){
        if(i >= n) return 0;
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int left = 0;
        int ans = 0;
        for(int k = i; k < j; k++){
            left += stoneValue[k];
            int right = total - left;
            if(left < right){
                ans = max(ans, left + rec(i, k, left, stoneValue, n, dp));
            }
            else if(left > right){
                ans = max(ans, right + rec(k + 1, j, right, stoneValue, n, dp));
            }
            else if(left == right){
                ans = max({ans, left + rec(i, k, left, stoneValue, n, dp), right + rec(k + 1, j, right, stoneValue, n, dp)});
            }
        }
        return dp[i][j] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int total = 0;
        int n = stoneValue.size();
        for(int x : stoneValue){
            total += x;
        }
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return rec(0, n - 1, total, stoneValue, n, dp);
    }
};