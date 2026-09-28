class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string>mp;
        for(vector<string>pairs : knowledge){
            mp[pairs[0]] = pairs[1];
        }
        string ans = "";
        string temp = "";
        bool flag = false;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                flag = true;
            }
            else if(s[i] == ')'){
                if(mp.find(temp) == mp.end()){
                    ans += '?';
                }
                else{
                    ans += mp[temp];
                }
                flag = false;
                temp = "";
            }
            else if(flag){
                temp += s[i];
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};