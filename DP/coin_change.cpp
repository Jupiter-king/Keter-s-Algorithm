#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define infinity 9999999

class Solution {
public:
    // 暴力递归法
    int coinChange1(vector<int> &coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;
        // 求最小值，res初始化为无穷大
        int res = infinity;
        for (int i = 0; i < coins.size(); i++) {
            int subProblem = coinChange1(coins, amount - coins[i]);
            if (subProblem == -1) continue;
            res = min(res, 1 + subProblem);
        }
        if (res != infinity)
            return res;
        return -1;
    }

    // 带有备忘录的递归算法
    int coinChange2(vector<int> &coins, int amount) {
        vector<int> memo(amount + 1, -666);
        return dp(coins, memo, amount);
    }

    // dp数组迭代法
    int coinChange3(vector<int> &coins, int amount) {
        // 数组大小为amount+1 , 初始值也为 amount + 1
        vector<int> dp(amount + 1, amount + 1);
        // 基础情况
        dp[0] = 0;
        // 外层for循环在遍历所有状态的所有值
        for (int i = 0; i < dp.size(); ++i) {
            // 内层循环求所有选择的最小值
            for (int coin : coins) {
                if (i - coin < 0) continue;
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
private:
    int dp(vector<int> &coins, vector<int> &memo, int n) {
        if (memo[n] != -666) return memo[n];
        if (n == 0) return 0;
        if (n < 0) return -1;
        int res = infinity;
        for (int i = 0; i < coins.size(); ++i) {
            int subProblem = dp(coins, memo, n - coins[i]);
            if (subProblem == -1) continue;
            res = min(res, 1 + subProblem);
        }
        // 计入备忘录中
        if (res != infinity)
            memo[n] = (int) res;
        else
            memo[n] = -1;
        return memo[n];
    }
};

int main() {
    vector<int> coins;
    coins.push_back(1);
    coins.push_back(2);
    coins.push_back(5);
    int amount = 11;
    cout << Solution().coinChange1(coins, amount) << endl;
    cout << Solution().coinChange2(coins, amount) << endl;
    cout << Solution().coinChange3(coins, amount) << endl;
    return 0;
}


