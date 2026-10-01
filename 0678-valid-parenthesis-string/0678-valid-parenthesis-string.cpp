class Solution {
public:
    bool rec(int i, int& n, string& s, int count, vector<vector<int>>& dp){
        if(i >= n){
            if(count == 0) return true;
            return false;
        }
        if(count < 0) return false;
        if(dp[i][count] != -1) return dp[i][count];
        bool ans = false;
        if(s[i] == '*'){
            ans = ans || rec(i + 1, n, s, count + 1, dp);
            ans = ans || rec(i + 1, n, s, count - 1, dp);
            ans = ans || rec(i + 1, n, s, count, dp);
        }
        else if(s[i] == '('){
            ans = ans || rec(i + 1, n, s, count + 1, dp);
        }
        else if(s[i] == ')'){
            ans = ans || rec(i + 1, n, s, count - 1, dp);
        }
        return dp[i][count] = ans;
    }
    bool checkValidString(string s) {
        if(s.size() == 0) return false;
        int n = s.size();
        vector<vector<int>>dp(n + 1, vector<int>(102, -1));
        return rec(0, n, s, 0, dp);
    }
};