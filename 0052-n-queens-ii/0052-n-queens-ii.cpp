class Solution {
public:
    int ans1 = 0;
    bool check(int row, int col, vector<string>& board, int n){
        int duprow = row;
        int dupcol = col;

        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        row = duprow;
        col = dupcol;

        while(dupcol >= 0){
            if(board[row][dupcol] == 'Q') return false;
            dupcol--;
        }

        duprow = row;
        dupcol = col;

        while(row < n && col >= 0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        return true;
    }
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n){
        if(col == n){
            ans.push_back(board);
            ans1++;
            return;
        }

        for(int row = 0; row < n; row++){
            if(check(row, col, board, n)){
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> board(n, s);
        solve(0, board, ans, n);
        return ans1;
    }
};