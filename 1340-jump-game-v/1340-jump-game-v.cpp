class Solution {
public:
    int solve(int i, int& n, int& d, vector<int>& arr, vector<int>& dp) {
        if (i < 0 && i >= n)
            return 0;
        if(dp[i] != -1){
            return dp[i];
        }
        int ans = 1;
        for (int j = 1 ; j <= d && i - j >= 0 ; j++) {
            if (arr[i - j] >= arr[i])
                break;

            ans = max(ans, 1 + solve(i - j, n, d, arr, dp));
        }

        for (int j = i + 1; j <= i + d && j < n; j++) {
            if (arr[j] >= arr[i])
                break;
            ans = max(ans, 1 + solve(j, n, d, arr, dp));
        }

        return dp[i] = ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        int res = INT_MIN;
        int n = arr.size();
        vector<int>dp(n, -1);
        for (int i = 0; i < n; i++) {
            res = max(res, solve(i, n, d, arr, dp));
        }
        return res;
    }
};