class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<pair<int, int>>vp[n];
        for(auto i : edges){
            vp[i[0]].push_back({i[1], i[2]});
            vp[i[1]].push_back({i[0], i[2]});
        }
        priority_queue<pair<int,pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        vector<int>dist(n , 1e9);
        dist[0] = 0;
        pq.push({passingFees[0],{0, 0}});
        while(!pq.empty()){
            int cost1 = pq.top().first;
            int time1 = pq.top().second.first;
            int node = pq.top().second.second;
            pq.pop();
            if (node == n - 1) return cost1;
            for(auto it : vp[node]){
                int adjnode = it.first;
                int time2 = it.second;
                int cost2 = passingFees[adjnode];

                if(time1 + time2 <= maxTime){
                    if(dist[adjnode] > time1 + time2){
                        dist[adjnode] = time1 + time2;
                        pq.push({cost1 + cost2, {time1 + time2, adjnode}});
                    }
                }
            }
        }
        return dist[n - 1] == 1e9 ? -1 : dist[n - 1];
    }
};