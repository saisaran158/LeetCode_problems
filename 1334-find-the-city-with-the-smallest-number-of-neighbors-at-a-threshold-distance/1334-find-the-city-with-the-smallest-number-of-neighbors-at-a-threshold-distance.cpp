class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>floyd(n, vector<int>(n, 1e9));
        for(int i = 0; i < n; i++)
        floyd[i][i] = 0;
        for(auto at : edges){
            floyd[at[0]][at[1]] = at[2];
            floyd[at[1]][at[0]] = at[2];
        }

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
                }
            }
        }
        
        int minCity = INT_MAX;
        int city = 0;
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < n; j++){
                if(floyd[i][j] <= distanceThreshold){
                    count++;
                }
            }
            minCity = min(count, minCity);
            if(count <= minCity){
            city = i;
            }
        }
        return city;
    }
};