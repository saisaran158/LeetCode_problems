class Solution {
public:
    int minDays(int n) {
        queue<pair<pair<int, int>, int>>q;
        q.push({{1, 1}, 1});
        vector<vector<bool>>vis(n + 1, vector<bool>(447 + 1, false));
        vis[1][1] = true;
        while(!q.empty()){
            int day = q.front().first.first;
            int score = q.front().first.second;
            int streak = q.front().second;
            q.pop();
            
            if(score == n) return day;
            if(score + streak + 1 <= n && !vis[score + streak + 1][streak + 1]){
                q.push({{day + 1, score + streak + 1}, streak + 1});
                vis[score + streak + 1][streak + 1] = true;
            }
            if(!vis[score][0]){
                q.push({{day + 1, score}, 0});
                vis[score][0] = true;
            }
        }
        return 0;
    }
};