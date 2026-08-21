class Solution {
public:
    bool solve(string &s, string &p, int& m, int& n, int i, int j) {
        if (i >= m && j >= n) {
            return true;
        }
        if (j >= n) {
            return false;
        }

        bool first = s[i] == p[j] || p[j] == '.' && i < m;

        bool ans;
        if (j + 1 < n && p[j + 1] == '*') {
            ans = solve(s, p, m, n, i, j + 2);

            if (first) {
                ans = ans || solve(s, p, m, n, i + 1, j);
            }
        } else {
            ans = first && solve(s, p, m, n, i + 1, j + 1);
        }
        return ans;
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        return solve(s, p, m, n, 0, 0);
    }
};