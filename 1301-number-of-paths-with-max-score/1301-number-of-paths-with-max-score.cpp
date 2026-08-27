class Solution {
public:
    int count = 0;
    long long mod = 1e9 + 7;
    int solve1(vector<string>& board, int r, int c, vector<vector<int>>& dp1) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board.size() ||
            board[r][c] == 'X') {
            return -1e9;
        }
        if (r == 0 && c == 0) {
            return 0;
        }
        if (dp1[r][c] != -1)
            return dp1[r][c];
        int num = 0;
        if (isdigit(board[r][c]))
            num = board[r][c] - '0';

        num +=
            max({solve1(board, r, c - 1, dp1), solve1(board, r - 1, c - 1, dp1),
                 solve1(board, r - 1, c, dp1)});
        return dp1[r][c] = num;
    }
    int solve2(vector<string>& board, int r, int c, int sum, int max,
               vector<vector<vector<int>>>& dp2) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board.size() ||
            board[r][c] == 'X') {
            return 0;
        }
        if (r == 0 && c == 0 && sum == max) {
            return 1;
        }
        if (sum > max)
            return 0;
        if (dp2[r][c][sum] != -1)
            return dp2[r][c][sum];
        int num = 0;
        if (isdigit(board[r][c]))
            num = board[r][c] - '0';

        int a = solve2(board, r, c - 1, sum + num, max, dp2) % mod;
        int b = solve2(board, r - 1, c - 1, sum + num, max, dp2) % mod;
        int d = solve2(board, r - 1, c, sum + num, max, dp2) % mod;
        return dp2[r][c][sum] = (a + b + d) % mod;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<int>> dp1(n, vector<int>(n, -1));
        int maxi = solve1(board, n - 1, n - 1, dp1);
        if(maxi < 0)
        return {0, 0};
        vector<vector<vector<int>>> dp2(
            n, vector<vector<int>>(n, vector<int>(maxi + 1, -1)));
        int ways = solve2(board, n - 1, n - 1, 0, maxi, dp2);
        return {maxi, ways};
    }
};