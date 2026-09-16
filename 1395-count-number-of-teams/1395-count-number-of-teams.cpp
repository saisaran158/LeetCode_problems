class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        int n = rating.size();
        for(int i = 0; i < n; i++){
            int a = 0;
            int b = 0;
            int c = 0;
            int d = 0;

            for(int j = 0; j < i; j++){
                if(rating[j] < rating[i]){
                    a++;
                }
                else{
                    b++;
                }
            }

            for(int k = i + 1; k < n; k++){
                if(rating[i] < rating[k]){
                    c++;
                }
                else{
                    d++;
                }
            }

            ans += a * c;
            ans += b * d;
        }
        return ans;
    }
};