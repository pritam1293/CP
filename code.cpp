#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
     // int n;
     //    ll k;
     //    cin >> n >> k;
 
     //    vector<ll> a(n);
     //    for (int i = 0; i < n; ++i)
     //        cin >> a[i];
 
     //    ll beauty = 0;
     //    vector<ll> upgrades;
 
     //    for (int i = 0; i < n; ++i) {
     //        ll x = a[i];
     //        beauty += __builtin_popcountll(x);
 
     //        // Generate upgrade steps
     //        while (true) {
     //            int pos = __builtin_ctzll(~x); // position of lowest 0-bit
     //            ll cost = 1LL << pos;
     //            if (k < cost) break;
     //            upgrades.push_back(cost);
     //            x += cost; // flip the 0-bit at position pos
     //        }
     //    }
 
     //    // Sort upgrades by cost and pick cheapest until k is exhausted
     //    sort(upgrades.begin(), upgrades.end());
     //    for (ll cost : upgrades) {
     //        if (k >= cost) {
     //            k -= cost;
     //            ++beauty;
     //        } else break;
     //    }
 
     //    cout << beauty << '\n';
    int n = 9;
    // for(int i = 0; i < 7; i++) {
    //     cout<<(1 & (n >> i));
    // }
    cout<<(1 & (2 >> 0));
}