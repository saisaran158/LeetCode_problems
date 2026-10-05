class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        for (int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(0);
            }
            else{
                int curr = st.top();
                st.pop();
                if(curr == 0){
                    st.push(1);
                }
                else{
                    st.push(curr * 2);  
                }

                int nw = st.top();
                st.pop();
                st.top() += nw;
            }
        }
        return st.top();
    }
};