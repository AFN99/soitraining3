#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
vector <pii> ss;
vector <pii> B;
vector <pii> ansb;
int main() {
    int n, s, pi, vi;
    char c;
    cin >> n >> s;
    while (n--) {
        cin >> c >> pi >> vi;
        if (c == 'S') {
            ss.push_back(mp(pi, vi));
        }
        else {
            B.push_back(mp(pi, vi));
        }
    }
    sort(ss.begin(), ss.end());
    int cnt = 0;
    int j;
    int curv;
    for (int i = 0; i < ss.size();) {
        if (cnt == s) break;
        curv = 0;
        for (j = i; j < ss.size() && ss[j].F == ss[i].F; j++) curv += ss[j].S;
        ansb.push_back(mp(ss[i].F, curv));
        cnt++;
        i = j;
    }
    for (int i = ansb.size() - 1; i >= 0; i--) {
        cout << "S " << ansb[i].F << ' ' << ansb[i].S << '\n';
    }
    sort(B.begin(), B.end());
    cnt = 0;
    for (int i = B.size() - 1; i >= 0;) {
        if (cnt == s) break;
        curv = 0;
        for (j = i; j >= 0 && B[j].F == B[i].F; j--) curv += B[j].S;
        cout << "B " << B[i].F << ' ' << curv << '\n';
        cnt++;
        i = j;
    }
    return 0;
}
