```
name{DP} 
introduce{动态规划算法学习}
```

# 动态规划

## 基本的定义

动态规划问题的一般形式就是求最值。
动态规划其实是运筹学的一种最优化方法，只不过在计算机问题上应用比较多，比如说让你求最长递增子序列呀，最小编辑距离呀等等。

既然是要求最值，核心问题是什么呢？求解动态规划的核心问题是穷举。因为要求最值，肯定要把所有可行的答案穷举出来，然后在其中找最值呗。

动态规划的穷举有点特别，因为这类问题存在「重叠子问题」，如果暴力穷举的话效率会极其低下，所以需要「备忘录」或者「DP table」来优化穷举过程，避免不必要的计算。

而且，动态规划问题一定会具备「最优子结构」，才能通过子问题的最值得到原问题的最值。

另外，虽然动态规划的核心思想就是穷举求最值，但是问题可以千变万化，穷举所有可行解其实并不是一件容易的事，只有列出正确的「状态转移方程」才能正确地穷举。

## 动态规划框架

- [x] 最基本框架
```python
# 初始化 base case
dp[0][0][...] = base
# 进行状态转移
for 状态1 in 状态1的所有取值：
    for 状态2 in 状态2的所有取值：
        for ...
            dp[状态1][状态2][...] = 求最值(选择1，选择2...)
```

- [x] 最短子序列的模版

模版来自力扣中的一道题目：[https://leetcode-cn.com/problems/longest-palindromic-subsequence/submissions/](https://leetcode-cn.com/problems/longest-palindromic-subsequence/submissions/)

```c++
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
```

- [x] 博弈问题模版

模版来源于力扣的一道题目：[https://leetcode-cn.com/problems/stone-game/submissions/](https://leetcode-cn.com/problems/stone-game/submissions/)

```c++
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
``` 

- [x] 贪心算法之区间调度问题

什么是贪心算法呢？贪心算法可以认为是动态规划算法的一个特例，相比动态规划，使用贪心算法需要满足更多的条件（贪心选择性质），但是效率比动态规划要高。

比如说一个算法问题使用暴力解法需要指数级时间，如果能使用动态规划消除重叠子问题，就可以降到多项式级别的时间，如果满足贪心选择性质，那么可以进一步降低时间复杂度，达到线性级别的。

力扣中可刷的题：

[435. 无重叠区间](https://leetcode-cn.com/problems/non-overlapping-intervals/)

[452.用最少数量的箭引爆气球](https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons)

两道题的思路可以说是一摸一样的；

- [x] KMP 算法

 pat 表示模式串，长度为 M，txt 表示文本串，长度为 N。KMP 算法是在 txt 中查找子串 pat，如果存在，返回这个子串的起始索引，否则返回 -1。

KMP 算法永不回退 txt 的指针 i，不走回头路（不会重复扫描 txt），而是借助 dp 数组中储存的信息把 pat 移到正确的位置继续匹配，时间复杂度只需 O(N)，用空间换时间，所以我认为它是一种动态规划算法。

KMP 算法的难点在于，如何计算 dp 数组中的信息？如何根据这些信息正确地移动 pat 的指针？这个就需要确定有限状态自动机来辅助了，别怕这种高大上的文学词汇，其实和动态规划的 dp 数组如出一辙，等你学会了也可以拿这个词去吓唬别人。

还有一点需要明确的是：计算这个 dp 数组，**只和 pat 串有关**。意思是说，只要给我个 pat，我就能通过这个模式串计算出 dp 数组，然后你可以给我不同的 txt，我都不怕，利用这个 dp 数组我都能在 O(N) 时间完成字符串匹配。



