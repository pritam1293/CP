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

void solve() {
    int n, k;
    cin>>n>>k;
    if(k % 2 == 1) {
        for(int i = 0; i < n; i++) {
            int a;
            cin>>a;
            if(a % 2 == 1) a += k;
            cout<<a<<" ";
        }
    }
    else {
        for(int i = 0; i < n; i++) {
            int a;
            cin>>a;
            int fact = a % (k+1);
            cout<< a + fact * k <<" ";
        }
    }
    cout<<endl;
}