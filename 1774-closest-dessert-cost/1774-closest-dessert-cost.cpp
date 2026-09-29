class Solution {
public:
    void rec(int i, vector<int>&toppingCosts, int& target, int sum, int& ans, int& n){
        if(i >= n){
            if(abs(sum - target) < abs(ans - target) || (abs(sum - target) == abs(ans - target) && sum < ans)){
                ans = sum;
            }
            return;
        }

        rec(i + 1, toppingCosts, target, sum, ans, n);

        for(int j = 0; j <= 2; j++){
            rec(i + 1, toppingCosts, target, sum + (j * toppingCosts[i]), ans, n);
        }
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int n = toppingCosts.size();
        int ans = 1e9;
        for(int i = 0; i < baseCosts.size(); i++){
            rec(0, toppingCosts, target, baseCosts[i], ans, n);
        }
        return ans;
    }
};