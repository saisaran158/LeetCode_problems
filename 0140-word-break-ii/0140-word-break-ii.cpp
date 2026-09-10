class Solution {
public:
    void recursion(int i, int& n, string& s, unordered_set<string>& set, string path, vector<string>& res){
        if(i >= n){
            path.pop_back();
            res.push_back(path);
        }

        string w="";
        for(int j = i; j < s.size(); j++){
            w += s[j];
            if(set.count(w)){
                cout << w << endl;
                recursion(j + 1, n, s, set, path + w + " ", res);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string>set(wordDict.begin(), wordDict.end());
        vector<string>res;
        recursion(0, n, s, set, "", res);
        return res;
    }
};