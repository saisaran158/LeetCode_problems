class Solution {
public:
    int recursion(int n){
        if(n == 1) return 0;

        int cost = 0;
        cost = n - 1;
        cost += recursion(n - 1); 
        return cost;
    }
    int minCost(int n) {
        return recursion(n);
    }
};