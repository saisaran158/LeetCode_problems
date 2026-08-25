class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        int maxA = INT_MIN;
        for (int i = 0; i <= n; i++) {
            while(!s.empty() && (i == n || heights[s.top()] >= heights[i])){
                int height = heights[s.top()];
                s.pop();
                int width;
                if(!s.empty()){
                    width = i - s.top() - 1;
                }
                else{
                    width = i;
                }
                maxA = max(maxA, width * height);
            }
            s.push(i);
        }
        return maxA;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = INT_MIN;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>heights(n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1'){
                    heights[j]++;
                }
                else{
                    heights[j] = 0;
                }
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }
};