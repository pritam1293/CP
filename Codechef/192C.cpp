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

int gcd(int a, int b) {
    return __gcd(a, b);
}

int lcm(int a, int b) {
    return (a*b)/gcd(a, b);
}

void solve() {
    int x, y, z, c;
    cin>>x>>y>>z>>c;
    if(x == y) {
        cout<<"0"<<endl;
        return;
    }
    if(x > y) swap(x, y);
    // if(lcm(x, z)  == gcd(y, z)) {
    //     cout<<c<<endl;
    //     return;
    // }
    if(y % x != 0) {
        cout<< 2*c <<endl;
        return;
    }
    int ans = 2*c;
    int div = y/x;
    for(int i=1;i*i <= div;i++) {
        if(div % i == 0) {
            if(lcm(x, x*i) == gcd(x*i, y)) {
                int diff = abs(z - x*i);
                ans = min(ans, diff+c);
            }
            int j = div/i;
            if(lcm(x, x*j) == gcd(x*j, y)) {
                int diff = abs(z - x*j);
                ans = min(ans, diff+c);
            }
        }
    }
    cout<<ans<<endl;
}