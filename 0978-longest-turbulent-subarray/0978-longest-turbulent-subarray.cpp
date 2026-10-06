class Solution {
public:
    int rec(int curr, int now, vector<int>& arr, int& n, vector<vector<int>>& dp){
        if(curr >= n) return 0;
        if(dp[curr][now] != -1) return dp[curr][now];
        int len = 0;

        if(arr[curr - 1] < arr[curr] && now == 0){
            len = 1 + rec(curr + 1, 1, arr, n, dp);
        }
        if(arr[curr - 1] > arr[curr] && now == 1){
            len = 1 + rec(curr + 1, 0, arr, n, dp);
        }
        return dp[curr][now] = len;
    }
    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 1;
        int n = arr.size();
        if(n == 1) return 1;
        vector<vector<int>>dp(n, vector<int>(2, -1));
        for(int i = 0; i < n - 1; i++){
            if(arr[i] < arr[i + 1])
            ans = max(ans, rec(i + 1, 0, arr, n, dp) + 1);
            else if(arr[i] > arr[i + 1])
            ans = max(ans, rec(i + 1, 1, arr, n, dp) + 1);
        }
        return ans;
    }
};