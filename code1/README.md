# Eratoshenes筛法

Eratoshenes筛选法是用来选择素数的算法。最佳的用法是用来筛选n以内的所有素数.

具体的操作就是：

求出sqrt(x)然后将\[2,n\]以内的所有数进行一次遍历，删除其中的\[1,sqrt(n)\]中素数的倍数。然后剩下的数就都是素数了。

- 判断单个数是不是素数：

只要判断\[1,sqrt(n)\]内有没有 n % i == 0（可以整除的情况）

```cpp
bool judge(long long n) {
    if (n < 2)
        return false;
    int sqrt_n = (int) sqrt(n);
    for (int i = 2; i <= sqrt_n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}
```