class Solution {
public:
    long long mod = 1e9 + 7;
    long long recursion(int i, string& s, int& k, vector<int>& dp){
        if(i >= s.size()) return 1;
        if(dp[i]!= -1) return dp[i];
        if(s[i] == '0') return 0;
        long long num = 0;
        long long ans = 0;
        for(int j = i; j < s.size(); j++){
            num = (num * 10) + s[j]- '0';
            if(num > k) break;
            if(num <= k){
                ans = (ans + recursion(j + 1, s, k, dp)) % mod;
            }
        }

        return dp[i] = ans % mod;
    }
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<int>dp(n + 1, -1);
        return recursion(0, s, k, dp);
    }
};