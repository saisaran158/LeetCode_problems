class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int s = 0;
        string res = "";
        while(num--){
            for(char a = '9'; a >= '0'; a--){
                // if(res.size() == 0 && a == '0') continue;
                if(s + (a - '0') <= sum){
                    res += a;
                    s += (a - '0');
                    break;
                }
            }
        }
        if(s != sum) return "";
        return res;
    }
};