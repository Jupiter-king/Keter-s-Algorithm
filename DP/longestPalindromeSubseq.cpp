#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
        // base case
        for (int i = 0; i < s.length(); ++i) {
            dp[i][i] = 1;
        }
        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = i + 1; j < s.length(); j++) {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][s.length() - 1];
    }
};


int main(){
    cout << Solution().longestPalindromeSubseq("bbbab");
}