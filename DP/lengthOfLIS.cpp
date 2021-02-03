#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        // dp 数组初始化
        vector<int> dp(nums.size(), 1);
        // 进行状态转移
        for (int i = 0; i < dp.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};


int main() {
    vector<int> a = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << Solution().lengthOfLIS(a) << endl;
    return 0;
}









