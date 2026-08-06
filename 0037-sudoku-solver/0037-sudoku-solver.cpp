class Solution {
public:
    bool check(vector<vector<char>>& board, char num, int row, int col) {
        for (int a = 0; a < 9; a++) {
            if (board[row][a] == num)
                return false;
            if (board[a][col] == num)
                return false;
            if (board[3 * (row / 3) + a / 3][3 * (col / 3) + a % 3] == num)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (char a = '1'; a <= '9'; a++) {
                        if (check(board, a, i, j)) {
                            board[i][j] = a;
                            if (solve(board) == true) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};