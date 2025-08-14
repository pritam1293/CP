#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void primeFactors(int n, map<int,int> &mp) {
    while(n % 2 == 0) {
        mp[2]++;
        n /= 2;
    }
    for(int i = 3; i*i <= n; i += 2) {
        while(n % i == 0) {
            mp[i]++;
            n /= i;
        }
    }
    if(n > 2) {
        mp[n]++;
    }
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    map<int,int> mp;
    for(auto& e : a) {
        primeFactors(e, mp);
    }
    for(auto& [f, s] : mp) {
        if(s % n != 0) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}