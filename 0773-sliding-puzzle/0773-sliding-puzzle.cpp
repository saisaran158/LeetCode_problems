class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<pair<vector<vector<int>>, int>>q;
        q.push({board, 0});
        set<vector<vector<int>>>s;
        vector<vector<int>>result = {{1, 2, 3}, {4, 5, 0}};
        s.insert(board);
        int delr[4] = {-1, 0, 1, 0};
        int delc[4] = {0, 1, 0, -1};
        while(!q.empty()){
            vector<vector<int>>ans = q.front().first;
            int step = q.front().second;
            q.pop();

            if(ans == result){
                return step;
            }
            int r, c;
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 3; j++){
                    if(ans[i][j] == 0){
                        r = i;
                        c = j;
                        break;
                    }
                }
            }
            for(int i = 0; i < 4; i++){
                int nr = r + delr[i];
                int nc = c + delc[i];

                if(nr >= 0 && nc >= 0 && nr < 2 && nc < 3){
                    swap(ans[nr][nc], ans[r][c]);
                    if(s.find(ans) == s.end()){
                        s.insert(ans);
                        q.push({ans, step + 1});
                    }
                    swap(ans[nr][nc], ans[r][c]);
                }

            }
        }
        return -1;
    }
};