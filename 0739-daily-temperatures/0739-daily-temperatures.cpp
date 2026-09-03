class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>>st;
        int n = temperatures.size();
        vector<int>res(n, 0);
        for(int i = 0; i < n; i++){
            while(!st.empty() && (st.top().first < temperatures[i])){
                res[st.top().second] = abs(i - st.top().second);
                st.pop();
            }
            st.push({temperatures[i], i});
        }
        return res;
    }
};