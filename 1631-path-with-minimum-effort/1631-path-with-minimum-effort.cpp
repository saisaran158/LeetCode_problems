class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>>dist(m, vector<int>(n, 1e9));
        dist[0][0] = 0;
        pq.push({0,{0, 0}});
        while(!pq.empty()){
            int eff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row == m - 1 && col == n - 1) return dist[row][col];
            int delr[] = {-1, 0, 1, 0};
            int delc[] = {0, 1, 0, -1};
            for(int i = 0; i < 4; i++){
                int nr = row + delr[i];
                int nc = col + delc[i];

                if(nr < m && nr >=0 && nc < n && nc >=0){
                    int ne = max(abs(heights[row][col] - heights[nr][nc]), eff);
                    if(ne < dist[nr][nc]){
                        dist[nr][nc] = ne;
                        pq.push({ne, {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};