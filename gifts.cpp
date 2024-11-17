#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORR(i, b, a) for (int i = (b); i >= (a); i--)
#define ll long long
#define endl "\n"
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int m, n;
    cin >> n >> m;
    int t[n];
    FOR (i, 0, n) cin >> t[i];

    int tcp[n];
    copy(t, t+n, tcp);
    sort(tcp, tcp+n);
    int maxTier = tcp[m-1];

    int maxTierCount = 0;
    for (int i = m-1; (i >= 0) && tcp[i] == maxTier; i--, maxTierCount++);

    FOR (i, 0, n) {
        if (t[i] < maxTier) cout << 1;
        else if (t[i] == maxTier && maxTierCount) {
            cout << 1;
            maxTierCount--;
        } else cout << 0;
        cout << " ";
    }
    cout << endl;

    return 0;
}
