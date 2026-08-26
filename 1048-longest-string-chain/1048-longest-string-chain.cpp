class Solution {
public:
    bool check(string a, string b){
        int m = a.size();
        int n = b.size();
        if(m != n + 1) return false;
        int i = 0, j = 0;
        while(i < m){
            if(a[i] == b[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(i == m && j == n) return true;
        return false;

    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(),[](auto a, auto b){
            return a.size() < b.size();
        });
        int n = words.size();
        int maxLen = 0;
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(check(words[i], words[prev]) && dp[i] < 1 + dp[prev]){
                    dp[i] = 1 + dp[prev];
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};