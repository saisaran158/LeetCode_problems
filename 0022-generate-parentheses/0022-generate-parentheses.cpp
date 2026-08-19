class Solution {
public:
    bool check(string s) {
        stack<char> a;
        if (s.size() == 1)
            return false;
        for (int i = 0; i < s.size(); i++) {
            if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{')) {
                a.push(s[i]);
            } else if (s[i] == ')') {
                if (a.empty())
                    return false;
                else if (a.top() == '(')
                    a.pop();
                else
                    a.push(s[i]);
            } else if (s[i] == ']') {
                if (a.empty())
                    return false;
                else if (a.top() == '[')
                    a.pop();
                else
                    a.push(s[i]);
            } else if (s[i] == '}') {
                if (a.empty())
                    return false;
                else if (a.top() == '{')
                    a.pop();
                else
                    a.push(s[i]);
            }
        }
        if (a.empty()) {
            return true;
        }
        return false;
    }
    void recursion(int ind, string str, vector<string>& ans, int end) {
        if (ind == end) {
            if (check(str)) {
                ans.push_back(str);
            }
            return;
        }

        recursion(ind + 1, str + "(", ans, end);
        recursion(ind + 1, str + ")", ans, end);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        recursion(1, "(", ans, n * 2);
        return ans;
    }
};