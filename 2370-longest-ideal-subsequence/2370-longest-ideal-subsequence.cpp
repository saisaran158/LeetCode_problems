class Solution {
public:
    int rec(int prev, int curr, int& n, string& s, int& k, vector<vector<int>>& dp){
        if(curr >= n) return 0;
        if(dp[prev + 1][curr] != -1) return dp[prev + 1][curr];
        int len = 0;
        if(prev == -1 || abs((prev + 97) - s[curr]) <= k){
            len = max(len, 1 + rec(s[curr] - 97, curr + 1, n, s, k, dp));
        }

        len = max(len, rec(prev, curr + 1, n, s, k, dp));

        return dp[prev + 1][curr] = len;
    }
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<vector<int>>dp(27, vector<int>(n + 1, -1));
        return rec(-1, 0, n, s, k, dp);
    }
};