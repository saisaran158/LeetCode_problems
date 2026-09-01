class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        vector<string>dup;
        for(string x : strs){
            sort(x.begin(), x.end());
            dup.push_back(x);
        }
        set<string>sets;
        for(int i = 0; i < strs.size(); i++){
            if(!sets.count(dup[i])){
                sets.insert(dup[i]);
            vector<string>row;
            row.push_back(strs[i]);
            for(int j = i + 1; j < strs.size(); j++){
                if(dup[i] == dup[j]){
                    row.push_back(strs[j]);
                }
            }
            res.push_back(row);
            }
        }
        return res;
    }
};