#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    // 暴力递归法
    int fib1(int n) {
        if (n < 1) return 0;
        else if (n == 1) return 1;
        else return fib1(n - 1) + fib1(n - 2);
    }

    // 带有备忘录的递归算法
    int fib2(int n) {
        if (n < 1) return 0;
        // 备忘录初始化为0
        vector<int> memo(n, 0);
        return helper(memo, n);
    }

    // dp数组迭代法
    int fib3(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        vector<int> dp(n + 1, 0);
        dp[1] = dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    // dp数组迭代法再优化
    int fib4(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        int prev = 1, curt = 1;
        int sum;
        for (int i = 3; i <= n; ++i) {
            sum = prev + curt;
            prev = curt;
            curt = sum;
        }
        return curt;
    }


private:
    int helper(vector<int> &memo, int n) {
        // 2也要加上
        if (n == 1 or n == 2) return 1;
        // 已经计算过了
        if (memo[n] != 0) return memo[n];
        memo[n] = helper(memo, n - 1) + helper(memo, n - 2);
        return memo[n];
    }
};

int main() {
    int n = 4;
    cout << Solution().fib1(n) << endl;
    cout << Solution().fib2(n) << endl;
    cout << Solution().fib3(n) << endl;
    cout << Solution().fib4(n) << endl;
    return 0;
}


