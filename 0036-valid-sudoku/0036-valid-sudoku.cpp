class Solution {
public:
    bool check(int row, int col, vector<vector<char>>& board) {
        char target = board[row][col];
        int c = 0;
        for (int a = 0; a < 9; a++) {
            if(board[row][a] == target){
                c++;
            }
            if(board[a][col] == target){
                c++;
            }
            if(board[3 * (row / 3) + a / 3][3 * (col / 3) + a % 3] == target){
                c++;
            }
        }
        return c >= 4;
    }
    bool solve(vector<vector<char>>& board, int& m, int& n) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.') {
                    if (check(i, j, board))
                        return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        return solve(board, m, n);
    }
};