class Solution {
public:
    bool recursion(int i, unordered_set<string>& set, string x, int count,
                   vector<int>& dp) {
        if (i >= x.size() && count >= 2) {
            return true;
        }
        if (dp[i] != -1)
            return dp[i];
        bool ans = false;
        string res = "";
        for (int j = i; j < x.size(); j++) {
            res += x[j];
            if (set.count(res)) {
                ans = ans || recursion(j + 1, set, x, count + 1, dp);
            }
        }
        return dp[i] = ans;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        unordered_set<string> set(words.begin(), words.end());
        for (string x : words) {
            int n = x.size();
            vector<int> dp(n + 1, -1);
            if (recursion(0, set, x, 0, dp)) {
                res.push_back(x);
            }
        }
        return res;
    }
};