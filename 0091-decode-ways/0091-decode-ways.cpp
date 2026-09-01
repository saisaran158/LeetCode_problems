class Solution {
public:

    int recursion(int i, int& n, string& s, map<string, int>&mp, vector<int>& dp){
        if(i == n) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        string r;
        for(int j = i; j < s.size(); j++){
            r += s[j];
            if(mp[r] == 1){
                ans += recursion(j + 1, n, s, mp, dp);
            }
        }
        return dp[i]= ans;

    }
    int numDecodings(string s) {
        int n = s.size();
        map<string, int>mp;
        for(int i = 1; i <= 26; i++){
            string a = to_string(i);
            mp[a]++;
        }
        vector<int>dp(n + 1, -1);
        return recursion(0, n, s, mp, dp);
    }
};