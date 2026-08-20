class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board, int& m, int& n){
        vis[row][col] = 1;
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++){
            int nr = row + delr[i];
            int nc = col + delc[i];
            if(nr >=0 && nc >= 0 && nr < m && nc < n && vis[nr][nc] == 0 && board[nr][nc] == 'O'){
                dfs(nr, nc, vis, board, m, n);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                dfs(0, i, vis, board, m, n);
            }
            if (board[m - 1][i] == 'O') {
                dfs(m - 1, i, vis, board, m, n);
            }
        }
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                dfs(i, 0, vis, board, m, n);
            }
            if (board[i][n - 1] == 'O') {
                dfs(i, n - 1, vis, board, m, n);
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' && vis[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }
    }
};