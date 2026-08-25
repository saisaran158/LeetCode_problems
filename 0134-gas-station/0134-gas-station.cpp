class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int n = gas.size();
        int currGas = 0;
        int totalGas = 0;
        for(int i = 0; i < n; i++){
            int diff = gas[i] - cost[i];
            currGas += diff;
            totalGas += diff;
            if(currGas < 0){
                start = i + 1;
                currGas = 0;
            }
        }
        if(totalGas < 0) return -1;
        return start;
    }
};