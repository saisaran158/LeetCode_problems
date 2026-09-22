class Solution {
public:
    vector<string> partitionString(string s) {
        vector<string>res;
        unordered_map<string, int>mp;
        string temp = "";
        for(int i = 0; i < s.size(); i++){
            temp += s[i];
            if(mp[temp] == 0){
                mp[temp] = 1;
                res.push_back(temp);
                temp = "";
            }
        }
        return res;
    }
};