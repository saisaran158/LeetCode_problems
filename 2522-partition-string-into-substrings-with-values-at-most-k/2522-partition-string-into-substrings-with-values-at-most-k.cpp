class Solution {
public:
    int rec(int i, int& n, string& s, int k, vector<int>& dp){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int len = 1e9;
        long long curr = 0;
        for(int j = i; j < n; j++){
            curr = (curr * 10) + s[j] - '0';
            if(curr > k) break;
            if(curr <= k){
                len = min(len, 1 + rec(j + 1, n, s, k, dp));
            }
        }
        return dp[i] = len;
    }
    int minimumPartition(string s, int k) {
        int n = s.size();
        vector<int>dp(n, -1);
        int ans =  rec(0, n, s, k, dp);
        if(ans >= 1e8 ) return -1;
        return ans;
    }
};