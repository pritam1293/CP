#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    long long k,l1,r1,l2,r2;
    cin>>k>>l1>>r1>>l2>>r2;

    vector<long long> powers;
    long long p = 1;

    while (p <= r2) {
        powers.push_back(p);
        if (p > r2 / k) break;
        p *= k;
    }

    long long cnt = 0;

    for (long long pow : powers) {

        long long minx = max(l1, (l2 + pow - 1ll) / pow);
        long long maxx = min(r1, r2 / pow);

        if (minx <= maxx) {
            cnt += maxx- minx + 1ll;
        }
    }

    cout<<cnt<<endl;
}
