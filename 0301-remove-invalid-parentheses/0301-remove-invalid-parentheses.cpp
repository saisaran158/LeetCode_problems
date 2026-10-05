class Solution {
public:
    void rec(int i, int& n, string& s, int c, string& path, vector<string>& res, unordered_map<string, int>& mp, int bal){
        if(i >= n){
            if(bal == 0 && mp[path] == 0){
                res.push_back(path);
                mp[path] = 1;
            }
            return;
        }
        if(bal < 0) return;
        if(c > 0 && !isalpha(s[i])){
            rec(i + 1, n, s, c - 1, path, res, mp, bal);
        }

        path.push_back(s[i]);
        if(s[i] == '(')
        rec(i + 1, n, s, c, path, res, mp, bal + 1);
        else if(s[i] == ')')
        rec(i + 1, n, s, c, path, res, mp, bal - 1);
        else
        rec(i + 1, n, s, c, path, res, mp, bal);
        path.pop_back();
    }
    vector<string> removeInvalidParentheses(string s) {
        int c = 0;
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (!isalpha(s[i])) {
                if (s[i] == '(') {
                    st.push(i);
                } else {
                    if (st.empty())
                        c++;
                    else {
                        st.pop();
                    }
                }
            }
        }
        c += st.size();
        int n = s.size();
        unordered_map<string, int>mp;
        vector<string>res;
        string path = "";
        rec(0, n, s, c, path, res, mp, 0);
        return res;
    }
};