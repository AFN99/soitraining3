#include <bits/stdc++.h>

using namespace std;
string s[50500];
bool mys(string a, string b) {
    return (a + b < b + a);
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    sort(s, s + n, mys);
    for (int i = 0; i < n; i++) cout << s[i];
    cout << '\n';
    return 0;
}
