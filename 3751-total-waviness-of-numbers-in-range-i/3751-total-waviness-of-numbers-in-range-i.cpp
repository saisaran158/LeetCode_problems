class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int c = 0;
        for(int i = num1; i <= num2; i++){
            string num = to_string(i);
            if(num.size() <= 2) continue;
            for(int j = 1; j < num.size() - 1; j++){
                if(num[j] - '0' > num[j - 1] -'0' && num[j] -'0' > num[j + 1] -'0'){
                    c++;
                }
                if(num[j] - '0' < num[j - 1] -'0' && num[j] -'0' < num[j + 1] -'0'){
                    c++;
                }
            }
        }
        return c;
    }
};