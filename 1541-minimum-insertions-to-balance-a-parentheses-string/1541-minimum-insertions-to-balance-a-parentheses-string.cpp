class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        stack<int> st;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (i + 1 < n && s[i] == ')' && s[i + 1] == ')') {
                if (st.empty()) {
                    ans++;
                } else
                    st.pop();
                i++;
            } else if (s[i] == ')') {
                if (st.empty()) {
                    ans += 2;
                } else {
                    st.pop();
                    ans++;
                }
            }
        }
        while (!st.empty()) {
            ans += 2;
            st.pop();
        }
        return ans;
    }
};