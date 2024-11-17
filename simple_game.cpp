#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORR(i, b, a) for (int i = (b); i >= (a); i--)
#define ll long long
#define endl "\n"
using namespace std;

typedef struct {
    int a;
    int b;
    bool used;
    int id;
} mypair;

bool comparea(const mypair &a, const mypair &b) {
    if (a.a == b.a)
        return a.b > b.b;
    else
        return a.a > b.a;
}

bool compareb(const mypair &a, const mypair &b) {
    if (a.b == b.b)
        return a.a > b.a;
    else
        return a.b > b.b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    mypair arra[n];
    mypair arrb[n];
    FOR(i, 0, n) {
        mypair p;
        cin >> p.a >> p.b;
        p.used = false;
        p.id = i;
        arra[i] = p;
        arrb[i] = p;
    }

    sort(arra, arra + n, &comparea);
    sort(arrb, arrb + n, &compareb);

    FOR(i, 0, n) {
        cout << arra[i].id << " " << arra[i].a << " " << arra[i].b << ", ";
        cout << arrb[i].id << " " << arrb[i].a << " " << arrb[i].b << endl;
    }
    // return 0;

    int ans = 0;
    int turn = 0;
    int aidx = 0, bidx = 0;
    while (n > 0) {
        while (1) {
            if (!arra[aidx].used) {
                break;
            }
            aidx++;
        }
        while (1) {
            if (!arrb[bidx].used) {
                break;
            }
            bidx++;
        }

        if (turn == 0) {
            if ((arra[aidx].a - arrb[bidx].b) >
                arrb[bidx].a - arra[aidx].b) {
                ans += arra[aidx].a;
                arra[aidx].used = true;
                cout << arra[aidx].id << " " << arra[aidx].a << " " << arra[aidx].b << endl;
            } else {
                ans += arrb[bidx].a;
                arrb[bidx].used = true;
                cout << arrb[bidx].id << " " << arrb[bidx].a << " " << arrb[bidx].b << endl;
            }
        } else {
            if ((-arrb[bidx].b + arra[aidx].a) <
                -arra[aidx].b + arrb[bidx].a) {
                ans -= arrb[bidx].b;
                arrb[bidx].used = true;
                cout << arrb[bidx].id << " " << arrb[bidx].a << " " << arrb[bidx].b << endl;
            } else {
                ans -= arra[aidx].b;
                arra[aidx].used = true;
                cout << arra[aidx].id << " " << arra[aidx].a << " " << arra[aidx].b << endl;
            }
        }
        n--;
        turn ^= 1;
    }
    cout << ans << endl;

    return 0;
}
