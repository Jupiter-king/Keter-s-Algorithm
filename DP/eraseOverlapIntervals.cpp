#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp1(vector<int> a, vector<int> b)//int为数组数据类型
{
    return a[1] < b[1];
}

class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if (intervals.size() <= 0) return 0;
        int count = 1;
        int i, j;
        // sort the array
        sort(intervals.begin(), intervals.end(), cmp1);
        // calculate count
        int x_end = intervals[0][1];
        int start;
        for (vector<int> interval : intervals) {
            start = interval[0];
            if (start >= x_end) {
                count++;
                x_end = interval[1];
            }
        }
        return intervals.size() - count;
    }

};

int main() {
    vector<vector<int>> intervals;
    intervals.push_back(vector<int>({1, 100}));
    intervals.push_back(vector<int>({11, 22}));
    intervals.push_back(vector<int>({1, 11}));
    intervals.push_back(vector<int>({2, 12}));
    cout << Solution().eraseOverlapIntervals(intervals);
    return 0;
}










