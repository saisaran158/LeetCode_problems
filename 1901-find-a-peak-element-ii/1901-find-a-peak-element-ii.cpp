class Solution {
public:
    int check(vector<vector<int>>& mat, int col){
        int row = 0;
        int maxy = -1e9;
        for(int i = 0; i < mat.size(); i++){
            if(mat[i][col] > maxy){
                maxy = mat[i][col];
                row = i;
            }
        }
        return row;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int high = mat[0].size() - 1;
        int low = 0;
        int mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            int row = check(mat, mid);
            int left = mid - 1 < 0 ? -1 : mat[row][mid - 1];
            int right = mid + 1 >= mat[0].size() ? -1 : mat[row][mid + 1];

            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row, mid};
            }

            else if(mat[row][mid] > right){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return {-1, -1};

    }
};