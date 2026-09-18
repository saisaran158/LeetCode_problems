class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string, int> mp;
        for (string x : bannedWords) {
            mp[x]++;
        }
        int ans = 0;
        for (string a : message) {
            if (mp.find(a) != mp.end()) {
                ans++;
            }
            if(ans == 2) return true;
        }
        return false;
    }
};