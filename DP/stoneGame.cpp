#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    bool stoneGame(vector<int> &piles) {
        // 创建dp二维数组
        pair<int, int> base(0, 0);
        vector<vector<pair<int, int>>> dp(piles.size(), vector<pair<int, int>>(piles.size(), base));
        // base case
        for (int i = 0; i < piles.size(); ++i) {
            dp[i][i] = pair<int, int>(piles[i], 0);
        }
        // 斜着遍历数组
        for (int l = 2; l <= piles.size(); ++l) {
            for (int i = 0; i <= piles.size() - l; ++i) {
                int j = l + i - 1;
                // 先手选择左边
                int left = piles[i] + dp[i + 1][j].second;
                // 先手选择右边
                int right = piles[j] + dp[i][j - 1].second;
                // 套入状态转化方程
                if (left > right) {
                    dp[i][j].first = left;
                    dp[i][j].second = dp[i+1][j].first;
                } else{
                    dp[i][j].first = right;
                    dp[i][j].second = dp[i][j-1].first;
                }
            }
        }
        if ((dp[0][piles.size()-1].first-dp[0][piles.size()-1].second) > 0)
            return true;
        else
            return false;
    }
};

int main() {
    vector<int> a = {3, 9, 1, 2};
    cout << Solution().stoneGame(a);
}
