class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        map<string, int> indegree;
        for (int i = 0; i < recipes.size(); i++) {
            indegree[recipes[i]] = ingredients[i].size();
        }
        set<string>s(recipes.begin(), recipes.end());
        map<string, vector<string>> mp;
        for (int i = 0; i < recipes.size(); i++) {
            for (int j = 0; j < ingredients[i].size(); j++) {
                mp[ingredients[i][j]].push_back(recipes[i]);
            }
        }

        vector<string> res;
        queue<string> q;
        for (auto x : supplies) {
            q.push(x);
        }

        while(!q.empty()){
            string node = q.front();
            q.pop();
            if(s.count(node)){
                res.push_back(node);
            }

            for(auto l : mp[node]){
                indegree[l]--;
                if(indegree[l] == 0){
                    q.push(l);
                }
            }
        }
        return res;

        return res;
    }
};