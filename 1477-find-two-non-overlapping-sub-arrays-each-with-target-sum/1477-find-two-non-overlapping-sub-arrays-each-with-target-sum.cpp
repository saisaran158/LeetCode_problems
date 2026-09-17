class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int>prefix(n);
        vector<int>suffix(n);
        int len1 = 1e8;
        int left = 0;
        int sum = 0;
        for(int right = 0; right < n; right++){
            sum += arr[right];
            while(sum > target){
                sum -= arr[left];
                left++;
            }
            if(sum == target){
                len1 = min(len1, right - left + 1);
            }
            prefix[right] = len1;
        }
        sum = 0;
        int len2 = 1e8;
        int right = n - 1;
        for(int j = n - 1; j >= 0; j--){
            sum += arr[j];
            while(sum > target){
                sum -= arr[right];
                right--;
            }
            if(sum == target){
                len2 = min(len2, right - j + 1);
            }
            suffix[j] = len2;
        }
        int ans = 1e9;
        for(int i = 0; i < n - 1; i++){
            ans = min(prefix[i] + suffix[i + 1], ans);
        }
        return ans >= 1e8 ? -1 : ans;
    }
};