class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses);
        vector<int>adj[numCourses];
        for(auto i : prerequisites){
            indegree[i[0]]++;
            adj[i[1]].push_back(i[0]);
        }
        queue<int>q;
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0)
                q.push(it);
            }
        }
        if(topo.size() != numCourses) return {};
        return topo;
    }
};