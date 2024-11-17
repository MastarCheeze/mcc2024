#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORR(i, b, a) for (int i = (b); i >= (a); i--)
#define ll long long
#define endl "\n"
using namespace std;

ll modexp(ll b, ll e, ll m) {
    ll tmp = e;
    ll mask = 1;
    while ((tmp >>= 1) != 0) {
        mask <<= 1;
    }

    ll total = 1;
    while (mask != 0) {
        total *= total;
        total %= m;
        if (mask & e) {
            total *= b;
        }
        total %= m;
        mask >>= 1;
    }

    return total;
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);

    ll mod = 998244353;

    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    ll a0 = 0, b0 = 0, c0 = 0;
    int count;
    FOR(i, 0, n - 1) {
        count = ((i+1) * (n-i-1)) % mod;
        if (s[i] == '0' && s[i + 1] == '0')
            a0 = (a0 + count) % mod;
        else if (s[i] == '1' && s[i + 1] == '1')
            c0 = (c0 + count) % mod;
        else
            b0 = (b0 + count) % mod;
    }

    cout << "a0=" << a0 << " b0=" << b0 << " c0=" << c0 << endl;

    ll ans = (a0 * modexp(2, k, mod)) % mod;
    cout << "a=" << ans << endl;

    ll b = b0, c = c0;
    ll temp;
    FOR (i, 0, k) {
        temp = c;
        c = b;
        b = (b + (2*temp) % mod) % mod;
    }
    ans = (ans + c) % mod;

    cout << ans << endl;

    return 0;
}
