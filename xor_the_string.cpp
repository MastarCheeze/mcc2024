#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORR(i, b, a) for (int i = (b); i >= (a); i--)
#define ll long long
#define endl "\n"
using namespace std;

ll transform(ll num, size_t numBits) {
    int transformed = 0;
    for (int mask = 1 << (numBits - 1); mask > 1; mask >>= 1) {
        bool bit = (bool)(num & mask) ^ (bool)(num & (mask >> 1));
        transformed |= (bool)(num & mask);
        transformed <<= 1;
        transformed |= bit;
        transformed <<= 1;
    }
    transformed |= (num & 1);
    return transformed;
}

int calcBeauty(ll num, size_t numBits) {
    int beauty = 0;
    for (int mask = 1 << (numBits - 1); mask > 1; mask >>= 1) {
        if (((bool)(num & mask) ^ (bool)(num & (mask >> 1))) == 0) beauty++;
    }
    return beauty;
}

string binStr(ll num, size_t numBits) {
    string out = "";
    for (int mask = 1 << (numBits - 1); mask >= 1; mask >>= 1)
        out += (num & mask) ? '1' : '0';
    return out;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

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

    ll b = b0, c = c0;
    ll temp;
    FOR (i, 0, k) {
        temp = c;
        c = b;
        b = (b + (2*temp) % mod) % mod;
    }

    ll ans = a0;
    FOR (i, 0, k) {
        ans = (ans * 2) % mod;
    }
    ans = (ans + c) % mod;

    cout << ans << endl;

    return 0;
}
