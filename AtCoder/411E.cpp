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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

int mod = 998244353;
 
int add(int a , int b) {
    return (mod + a%mod + b%mod)%mod;
}
 
int multi(int a , int b) {
    return ((a%mod) * (b%mod))%mod;
}
 
int binpower(int a , int b) {
    if(b == 0) {
        return 1;
    }
    int num = binpower(a , b/2);
    num = multi(num , num);
    if(b%2) {
        return multi(num , a);
    }
    return num;
}
 
int modinverse(int a) {
    return binpower(a , mod-2);
}

void solve() {
    int n;
    cin>>n;
    vector<map<int,int>> a(n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<6;j++) {
            int x;
            cin>>x;
            a[i][x]++;
        }
    }
    map<int,int> mp;
}