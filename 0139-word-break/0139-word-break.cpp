class Solution {
public:
    bool recursion(int i, string& s, unordered_map<string, int>& mp, vector<int>& dp){
        if(i == s.size()) return true;
        if(dp[i] != -1) return dp[i];
        string res = "";
        bool ans = false;
        for(int j = i; j < s.size(); j++){
            res += s[j];
            if(mp[res] == 1)
            ans = ans || recursion(j + 1, s, mp, dp);
        }
        return dp[i] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int>mp;
        for(string x : wordDict){
            mp[x]++;
        }
        int n = s.size();
        vector<int>dp(n, -1);
        return recursion(0, s, mp, dp);
    }
};