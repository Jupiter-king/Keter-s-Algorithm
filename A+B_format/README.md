```
name{A+B Format}
introduce{string format}
```

This practice is very easy. But I didn't solve it. Why I'm so vegetable (Chinese English x)

The main idea of this practice is `(i+1)%3 == len%3`.
I optimized this algorithm by solving a ',' will be printed at the end of the output. So I changed the max value of i. And let the procedure output the last character at last.

code:
```cpp
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
``` 