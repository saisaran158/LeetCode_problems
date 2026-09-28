class Solution {
public:
    void dfs(int i, vector<vector<int>>& rooms, vector<int>& vis){
        vis[i] = 1;

        for(int j = 0; j < rooms[i].size(); j++){
            if(!vis[rooms[i][j]]){
                dfs(rooms[i][j], rooms, vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>vis(n, 0);
        dfs(0, rooms, vis);
        for(int i = 0; i < n; i++){
            if(vis[i] == false) return false;
        }
        return true;
    }
};