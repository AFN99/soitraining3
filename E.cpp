#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
ll t[100100];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> t[i];
    sort(t, t + n);
    ll sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (sum > t[i]) continue;
        ans++;
        sum += t[i];
    }
    cout << ans << '\n';
    return 0;
}
