class Solution {
public:
    int delr[4] = {-1, 0, 1, 0};
    int delc[4] = {0, 1, 0, -1};
    int m, n;
    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<int>>& vis){
        vis[r][c] = 1;
        for(int i = 0; i < 4; i++){
            int nr = r + delr[i];
            int nc = c + delc[i];
            if(nr >= 0 && nc >= 0 && nr < m && nc < n && board[nr][nc] == 'X' && vis[nr][nc] == 0){
                dfs(nr, nc, board, vis);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        m = board.size();
        n = board[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (!vis[i][j] && board[i][j] == 'X'){
                    count++;
                    dfs(i, j, board, vis);
                }
            }
        }
        return count;
    }
};