class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int>mp;
        int n = s.size();
        for(int i = 0; i < n; i++){
            mp[s[i]] = i;
        }
        vector<int>res;
        int left = 0;
        for(int right = 0; right < n;){
            int ind = mp[s[right]];
            while(right < ind){
                right++;
                ind = max(ind, mp[s[right]]);
            }
            res.push_back(right - left + 1);
            right++;
            left = right;
        }
        return res;
    }
};