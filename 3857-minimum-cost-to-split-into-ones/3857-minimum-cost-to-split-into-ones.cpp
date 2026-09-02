class Solution {
public:
    int minCost(int n) {
        int c = n - 1;
        return c*(c+1)/2;
    }
};