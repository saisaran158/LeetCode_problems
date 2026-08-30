class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = -1e9;
        int n = cardPoints.size();
        int tot = 0;
        int ini = 0;
        for(int i = 0; i < n; i++){
            tot += cardPoints[i];
        }
        for(int i = 0; i < n - k; i++){
            ini += cardPoints[i];
        }
        ans = max(ans, tot - ini);
        for(int i = n - k; i < n; i++){
            ini += cardPoints[i];
            ini -= cardPoints[i - (n - k)]; 
            ans = max(ans, tot - ini);
        }
        return ans;
    }
};