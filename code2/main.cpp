#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;
const int maxNum = 1001;


// 重制时间
void reset(int *book) {
    for (int i = 0; i < maxNum; ++i) {
        book[i] = -1;
    }
}

// 将时间转化为分钟
int cnt(const string &t) {
    int totalTime = 0;
    totalTime += stoi(t.substr(0, 2)) * 60;
    totalTime += stoi(t.substr(3, 2));
    return totalTime;
}

int main() {
    int n;
    cin >> n;
    int id;
    int readTime = 0;
    int averageTime = 0;
    char action;
    string Time;
    int book[1001]; // 存储书籍的时间
    for (int i = 0; i < n; ++i) {
        reset(book);
        readTime = 0;
        averageTime = 0;
        cin >> id;
        cin >> action;
        cin >> Time;
        while (id != 0) {
            if (action == 'S') {
                book[id] = cnt(Time);
            } else if (action == 'E' and book[id] != -1) {
                averageTime += cnt(Time) - book[id];
                book[id] = -1;
                readTime += 1;
            }
            cin >> id;
            cin >> action;
            cin >> Time;
        }
        if (readTime == 0) {
            cout << readTime << " " << 0;
        } else {
            cout << readTime << " " << (int) (1.0 * averageTime / readTime + 0.5);
        }
        if (i != n - 1)
            cout << endl;
    }
    return 0;
}











