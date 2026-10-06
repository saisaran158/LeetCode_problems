class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int>mp;
        int left = 0;
        string str = "";
        int n = s.size();
        for(int right = 0; right < n; right++){
            str += s[right];
            if((right - left + 1) > 10){
                str.erase(0, 1);
                left++;
            }
            if((right - left + 1) == 10){
                mp[str]++;
            }
        }
        vector<string>res;
        for(auto x : mp){
            if(x.second > 1){
                res.push_back(x.first);
            }
        }
        return res;
    }
};