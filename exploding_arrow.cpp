#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORR(i, b, a) for (int i = (b); i >= (a); i--)
#define ll long long
#define endl "\n"
using namespace std;

ll powRequired(ll *start, ll *end, ll m) {
    ll x = 0;
    ll i = 0;
    while (i < end - start) {
        x = max(x, (ll)ceil((double)(start[i] + i * i) / m));
        i++;
    }
    return x;
}

vector<ll> damageDealt(ll x, ll m, int cap) {
    vector<ll> damages;
    ll damage;
    ll i = 0;
    while (i < cap) {
        damage = m * x - (i * i);
        if (damage <= 0) break;
        damages.push_back(damage);
        i++;
    }
    return damages;
}

int arrowsRequired(ll *start, ll *end, ll x, ll m) {
    ll n = end - start;
    ll target = 0;
    ll a[n];
    FOR(i, 0, n) a[i] = start[i];
    int count = 0;

    while (1) {
        vector<ll> damages = damageDealt(x, m, n - target);
        FOR(i, 0, damages.size()) { a[target + i] -= damages[i]; }
        count++;

        while (target < n) {
            if (a[target] > 0) break;
            target++;
        }

        if (target >= n) break;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;
    ll a[n];
    FOR(i, 0, n) cin >> a[i];

    ll maxPowRequired = powRequired(a, a + n, m);

    int ans = -1;
    for (int jump = maxPowRequired / 2; jump >= 1; jump /= 2) {
        while (arrowsRequired(a, a + n, ans + jump, m) > k) ans += jump;
    }
    ans += 1;

    cout << ans << endl;

    return 0;
}
