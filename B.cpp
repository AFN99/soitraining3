#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
struct node {
    int i;
    ll p;
    ll c;
};
bool mys(node x, node y) {
    return (x.p < y.p);
}
node a[100100];
ll ans[100100];
multiset <ll> s;
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i].p;
        a[i].i = i;
    }
    for (int i = 0; i < n; i++) cin >> a[i].c;
    if (k == 0) {
        cout << a[0].c;
        for (int i = 1; i < n; i++) cout << ' ' << a[i].c;
        cout << '\n';
        return 0;
    }
    sort(a, a + n, mys);
    int cnt = 1;
    int C = a[0].c;
    ans[a[0].i] = a[0].c;
    s.insert(a[0].c);
    set<ll>::iterator it;
    for (int i = 1; i < n; i++) {
        ans[a[i].i] = a[i].c + C;
        if (cnt < k) {
            s.insert(a[i].c);
            cnt++;
            C += a[i].c;
        }
        else {
            it = s.upper_bound(a[i].c);
            if (it == s.end() || *it > *s.begin()) {
                C -= *s.begin();
                C += a[i].c;
                s.erase(s.begin());
                s.insert(a[i].c);
            }
        }
    }
    cout << ans[0];
    for (int i = 1; i < n; i++) cout << ' ' << ans[i];
    cout << '\n';
    return 0;
}
