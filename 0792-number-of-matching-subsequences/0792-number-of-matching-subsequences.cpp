class Solution {
public:
    bool check(unordered_map<char, vector<int>>&mp, string curr){
        int prev = -1;
        int i = 0;
        while(i < curr.size()){
            int ind = upper_bound(mp[curr[i]].begin(), mp[curr[i]].end(), prev) - mp[curr[i]].begin();
            if(ind == mp[curr[i]].size()) return false;
            prev = mp[curr[i]][ind];
            i++;
        }
        return true;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>>mp;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]].push_back(i);
        }
        int ans = 0;
        for(string x : words){
            if(check(mp, x)){
                ans++;
            }
        }
        return ans;
    }
};