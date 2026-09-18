class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        if(n == 1) return arr[0];
        vector<int> left(n);
        vector<int> right(n);
        int flag = 0;
        left[0] = 0;
        int sum = 0;
        for (int i = 1; i < n; i++) {
            sum += arr[i - 1];
            if (sum < 0) {
                flag = 1;
                left[i] = 0;
                sum = 0;
            } else {
                left[i] = sum;
            }
        }
        right[n - 1] = 0;
        sum = 0;
        for(int i = n - 2; i >= 0; i--){
            sum += arr[i + 1];
            if(sum < 0){
                flag = 1;
                right[i] = 0;
                sum = 0;
            }
            else{
                right[i] = sum;
            }
        }
        if(flag == 0){
            int res = 0;
            for(int x : arr){
                res += x;
            }
            return res;
        }
        for(int i = 0; i < n; i++){
            ans = max(ans, left[i] + right[i]);
        }
        return ans == 0 ? -1 : ans;
    }
};