#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    int **KMP(string pat) {
        int M = pat.length();
        int **dp = new int *[M]();
        for (int i = 0; i < M; ++i) {
            dp[i] = new int[256]();
            memset(dp[i], 0, 256);
        }
        // base case
        dp[0][pat[0]] = 1;
        int X = 0; // 初始化影子状态
        for (int i = 1; i < M; ++i) {
            for (int j = 0; j < 256; ++j) {
                dp[i][j] = dp[X][j]; // 状态回退
            }
            dp[i][pat[i]] = i + 1; // 状态进位
            // 更新影子状态
            X = dp[X][pat[i]];
        }
        return dp;
    }

    int strStr(string haystack, string needle) {
        if (needle.length() == 0 or haystack == needle)
            return 0;
        int **dp = KMP(needle);
        int M = needle.length();
        int N = haystack.length();
        // 搜寻初始状态
        int j = 0;
        for (int i = 0; i < N; ++i) {
            j = dp[j][haystack[i]];
            if (j == M) return i - M + 1;
        }
        return -1;
    }

};

int main() {
    cout << Solution().strStr("hello", "ll");
    return 0;
}