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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    for(int i = 0; i < 1000; i++) {
        if(n == 1) {
            cout<<"Yes"<<endl;
            return;
        }
        int num = 0;
        while(n) {
            int d = n % 10;
            num += d*d;
            n /= 10;
        }
        n = num;
    }    
    cout<<"No"<<endl;
}