#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    string s = to_string(a + b);
    int len = s.length();
    for (int i = 0; i < s.length() - 1; i++) {
        cout << s[i];
        if (s[i] == '-') continue;
        if ((i + 1) % 3 == len % 3) cout << ',';
    }
    cout << s[s.length() - 1];
    return 0;
}





