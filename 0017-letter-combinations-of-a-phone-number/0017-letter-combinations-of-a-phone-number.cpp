class Solution {
public:
    void recursion(int i, string& digits, int n, unordered_map<int, string>& mp, vector<string>& res, string path){
        if(i == n){
            res.push_back(path);
            return;
        }

        for(auto it : mp[digits[i] -'0']){
            path.push_back(it);
            recursion(i + 1, digits, n, mp, res, path);
            path.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int, string>mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        vector<string>res;
        recursion(0, digits, digits.size(), mp, res, "");
        return res;
    }
};