class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>>dist(m, vector<int>(n, -1));
        queue<pair<int, int>>q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isWater[i][j] == 1){
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int delr[4] = {-1, 0, 1, 0};
        int delc[4] = {0, 1, 0, -1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nr = r + delr[i];
                int nc = c + delc[i];

                if(nr >= 0 && nc >= 0 && nr < m && nc < n && dist[nr][nc] == -1){
                    dist[nr][nc] = 1 + dist[r][c];
                    q.push({nr, nc});
                }
            }
        }
        return dist;
    }
};