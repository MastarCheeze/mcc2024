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

bool comparea(mypair *a, mypair *b) {
    if (a->a == b->a)
        return a->b > b->b;
    else
        return a->a > b->a;
}

bool compareb(mypair *a, mypair *b) {
    if (a->b == b->b)
        return a->a > b->a;
    else
        return a->b > b->b;
}

int nextUnused(mypair *arr[], int i, int n) {
    while (arr[i]->used && i < n*sizeof arr[0]) {
        i++;
    }
    return i;
}

string pairStr(const mypair *p) {
    return to_string(p->id) + ". a=" + to_string(p->a) + " b=" + to_string(p->b) + " used=" + to_string(p->used);
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int n;
    cin >> n;
    mypair *aPairs[n];
    mypair *(*paPairs)[] = &aPairs;
    mypair *bPairs[n];
    mypair *(*pbPairs)[] = &bPairs;
    FOR(i, 0, n) {
        aPairs[i] = (mypair *)malloc(sizeof(mypair));
        (*pbPairs)[i] = (*paPairs)[i];

        cin >> (*paPairs)[i]->a >> (*paPairs)[i]->b;
        (*paPairs)[i]->used = false;
        (*paPairs)[i]->id = i;
    }

    sort(*paPairs, *paPairs + n, &comparea);
    sort(*pbPairs, *pbPairs + n, &compareb);

    FOR(i, 0, n) {
        cout << pairStr((*paPairs)[i]) << ", ";
        cout << pairStr((*pbPairs)[i]) << endl;
    }
    cout << endl;

    int turn = 0;
    int ans = 0;
    int aTop = 0, bTop = 0;
    while (n > 0) {
        cout << "turn=" << turn << " aTop=" << aTop << " bTop=" << bTop << " | ";
        if (turn == 0) {
            if (
                (*paPairs)[aTop]->a - (*pbPairs)[bTop]->b >
                (*pbPairs)[bTop]->a - (*paPairs)[aTop]->b
            ) {
                cout << pairStr((*paPairs)[aTop]) << " diff=" << (*paPairs)[aTop]->a - (*pbPairs)[bTop]->b << " ans=" << ans << endl;
                ans += (*paPairs)[aTop]->a;
                (*paPairs)[aTop]->used = true;
            } else {
                cout << pairStr((*pbPairs)[bTop]) << " diff=" << (*pbPairs)[bTop]->a - (*paPairs)[aTop]->b << " ans=" << ans << endl;
                ans += (*pbPairs)[bTop]->a;
                (*pbPairs)[bTop]->used = true;
            }
        } else {
            if (
                -(*pbPairs)[bTop]->b + (*paPairs)[aTop]->a <
                -(*paPairs)[aTop]->b + (*pbPairs)[bTop]->a
            ) {
                cout << pairStr((*pbPairs)[bTop]) << " diff=" << -(*pbPairs)[bTop]->b + (*paPairs)[aTop]->a << " ans=" << ans << endl;
                ans -= (*pbPairs)[bTop]->b;
                (*pbPairs)[bTop]->used = true;
            } else {
                cout << pairStr((*paPairs)[aTop]) << " diff=" << -(*paPairs)[aTop]->b + (*pbPairs)[bTop]->a << " ans=" << ans << endl;
                ans -= (*paPairs)[aTop]->b;
                (*paPairs)[aTop]->used = true;
            }
        }
        aTop = nextUnused(aPairs, aTop, n);
        bTop = nextUnused(bPairs, bTop, n);
        n--;
        turn ^= 1;
    }
    cout << ans << endl;

    return 0;
}
