//
// Created by Keter on 2021/2/3.
//
#include <iostream>
#include <algorithm>
#include <map>
#include <utility>


using namespace std;

#define infinity 65535

class Solution {
public:
    map<pair<int, int>, int> memo;

    int superEggDrop(int K, int N) {
        if (K == 1) return N;
        if (N == 0) return 0;
        // 避免重复计算
        if (memo.find(pair<int, int>(K, N)) != memo.end())
            return memo[pair<int, int>(K, N)];
        int res = infinity;
        int low = 1, high = N;
        int mid, broken, notBroken;
        while (low <= high) {
            mid = floor((low + high)/2.0);
            broken = superEggDrop(K - 1, mid - 1);
            notBroken = superEggDrop(K, N - mid);
            if (broken > notBroken) {
                high = mid - 1;
                res = min(res, broken + 1);
            } else {
                low = mid + 1;
                res = min(res, notBroken + 1);
            };
        }
        // 计入备忘录
        memo[pair<int, int>(K, N)] = res;
        return res;
    }
};

int main() {
    cout << Solution().superEggDrop(2, 6) << endl;
    return 0;
}
