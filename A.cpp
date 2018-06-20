#include <bits/stdc++.h>

using namespace std;
int a[100100];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int ans = 0, j, f = 0;
    for (int i = 0; i < n;) {
        for (j = i; a[j] == a[i] && j < n; j++);
        ans++;
        if (a[i] == 0) f = -1;
        i = j;
    }
    cout << ans + f << '\n';
    return 0;
}
