class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        string change = "ACGT";
        queue<pair<string, int>>q;
        q.push({startGene, 0});
        unordered_map<string, int>mp;
        for(string x : bank) mp[x]++;
        while(!q.empty()){
            string curr = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(curr == endGene) return steps;
            for(int i = 0; i < 8; i++){
                char og = curr[i];
                for(int j = 0; j < 4; j++){
                    if(og == change[j]) continue;
                    curr[i] = change[j];
                    if(mp[curr] >= 1){
                        q.push({curr, steps + 1});
                        mp[curr] = 0;
                    }
                    curr[i] = og;
                }
            }
        }
        return -1;
    }
};