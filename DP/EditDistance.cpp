#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        int i, j;
        int m = word1.length();
        int n = word2.length();
        int dp[m + 1][n + 1];
        // base case
        dp[0][0] = 0;
        for (i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        for (j = 1; j <= n; j++) {
            dp[0][j] = j;
        }
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++)
                if (word1[i-1] == word2[j-1])
                    // don't change
                    dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = min(min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1), dp[i][j - 1] + 1);
                }
        }
        return dp[m][n];
    }
};


int main() {
    cout << Solution().minDistance("horse", "ros");
    return 0;
}







