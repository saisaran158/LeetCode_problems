class Solution {
public:
    int minDeletions(string s) {
        map<char, int>mp;
        for(char a : s){
            mp[a]++;
        }
        vector<int>freq;
        for(auto i : mp){
            freq.push_back(i.second);
        }
        sort(freq.rbegin(), freq.rend());
        int c = 0;
        set<int>ss;
        for(int i = 0; i < freq.size(); i++){
            while(ss.count(freq[i]) && freq[i] > 0){
                freq[i]--;
                c++;
            }
            ss.insert(freq[i]);
        }
        return c;
    }
};