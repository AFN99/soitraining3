#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node {
    ll s;
    ll h;
    string x;
};
node s[100100];
bool mys(node x, node y) {
    return x.s * y.h > y.s * x.h;
}
int main() {
    int n;
    cin >> n;
    string S = "";
    for (int i = 0; i < n; i++) {
        cin >> s[i].x;
        for (int j = 0; j < s[i].x.size(); j++) {
            if (s[i].x[j] == 's') s[i].s++;
            else s[i].h++;
        }
    }
    sort(s, s + n, mys);
    for (int i = 0; i < n; i++) S += s[i].x;
    ll cs = 0, ans = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 's') cs++;
        else ans += cs;
    }
    cout << ans << '\n';
    return 0;
}
