#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORR(i, b, a) for (int i = (b); i >= (a); i--)
#define ll long long
#define endl "\n"
using namespace std;

ll MOD = 998244353;

ll add(ll a, ll b) {
    return (a + b) % MOD;
}

ll mult(ll a, ll b) {
    return (a * b) % MOD;
}

ll power(ll b, ll e) {
    ll tmp = e;
    ll mask = 1;
    while ((tmp >>= 1) != 0) {
        mask <<= 1;
    }

    ll total = 1;
    while (mask != 0) {
        total = mult(total, total);
        if (mask & e) {
            total = mult(total, b);
        }
        mask >>= 1;
    }

    return total;
}

ll inv(ll a, ll b) {
    return power(b, MOD-2);
}

ll divide(ll a, ll b) {
    return mult(a % MOD, inv(a, b));
}

ll jacobsthal(ll k) {
    ll x = power(2, k);
    return divide(add(x, (k % 2 == 0) ? -1 : 1), 3);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    ll a0 = 0, b0 = 0, c0 = 0;
    int count;
    FOR(i, 0, n - 1) {
        count = mult(add(i, 1), add(add(n, -i), -1));
        if (s[i] == '0' && s[i + 1] == '0')
            a0 = add(a0, count);
        else if (s[i] == '1' && s[i + 1] == '1')
            c0 = add(c0, count);
        else
            b0 = add(b0, count);
    }

    ll ans = mult(a0, power(2, k));

    ans = add(ans, mult(add(b0,-c0), jacobsthal(k)));
    ans = add(ans, mult(c0, jacobsthal(k+1)));

    cout << ans << endl;

    return 0;
}