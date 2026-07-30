class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int n = heights.size();
        vector<int> ls(n, 0);
        vector<int> rs(n, 0);
        for(int i = 0; i < n; i++){
            while(st.top() != -1 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            ls[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        st.push(n);
        for(int i = n - 1; i >= 0; i--){
            while(st.top() != n && heights[st.top()] >= heights[i]){
                st.pop();
            }
            rs[i] = st.top();
            st.push(i);
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            res = max(res, heights[i]*(rs[i] - ls[i] - 1));
        }
        return res;
    }
};