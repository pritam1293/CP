#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n, q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    vector<int> prefix(2*n + 1);
    for(int i = 1; i <= 2*n; i++) {
        prefix[i] = prefix[i-1] + a[(i-1) % n];
    }
    int shift = 0;
    while(q--) {
        int t;
        cin>>t;
        if(t == 1) {
            int c;
            cin>>c;
            shift = (shift + c) % n;
        }
        else {
            int l, r;
            cin>>l>>r;
            l = (l - 1 + shift) % n + 1;
            r = (r - 1 + shift) % n + 1;
            if(l <= r) {
                cout<< prefix[r] - prefix[l-1] <<endl;
            }
            else {
                cout<< prefix[n] - prefix[l-1] + prefix[r] <<endl;
            }
        }
    }
}