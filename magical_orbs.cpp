#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORR(i, b, a) for (int i = (b); i >= (a); i--)
#define ll long long
#define endl "\n"
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        FOR (i, 0, n) cin >> a[i];
        ll mod = (1e9) + 7;

        sort(a, a+n);
        ll ans = 0;
        FORR (i, n-1, 0) {
            ans = ((a[i] % mod) + ((2 * ans) % mod)) % mod;
        }
        cout << ans % mod << endl;
    }

    return 0;
}
