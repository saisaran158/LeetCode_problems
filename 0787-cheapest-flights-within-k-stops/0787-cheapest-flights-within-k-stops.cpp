class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>>vp[n];
        for(auto i : flights){
            vp[i[0]].push_back({i[1], i[2]});
        }
        queue<pair<int, pair<int, int>>>q;
        q.push({0,{src, 0}});
        vector<int> dist(n , 1e9);
        dist[src] = 0;
        while(!q.empty()){
            int steps = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();

            for(auto it : vp[node]){
                int n = it.first;
                int c = it.second;

                if(cost + c < dist[n] && steps <= k){
                    dist[n] = cost + c;
                    q.push({steps + 1,{n, cost + c}});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};