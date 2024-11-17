#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORR(i, b, a) for (int i = (b); i >= (a); i--)
#define ll long long
#define endl "\n"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        ll n, m, A, B;
        cin >> n >> m >> A >> B;

        if (
            ((A == n || B == m) && (A <= n && B <= m)) ||
            ((A == m || B == n) && (A <= m && B <= n))
        )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
