class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int>row1;
        vector<int>col1;
        vector<vector<int>>ans(grid.size(), vector<int>(grid[0].size(), 0));
        for(int i = 0; i < grid.size(); i++){
            int c1 = 0;
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1)
                c1++;
            }
            row1.push_back(c1);
        }
         for(int i = 0; i < grid[0].size(); i++){
            int c2 = 0;
            for(int j = 0; j < grid.size(); j++){
                if(grid[j][i] == 1)
                c2++;
            }
            col1.push_back(c2);
        }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                ans[i][j] = row1[i] + col1[j] - (grid.size() - row1[i]) - (grid[0].size() - col1[j]);
            }
        }
        return ans;
    }
};