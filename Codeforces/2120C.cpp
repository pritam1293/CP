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
    int n, m;
    cin>>n>>m;
    int maxm = n * (n+1) / 2ll;
    if(m > maxm || m < n) {
        cout<<"-1"<<endl;
        return;
    }
    // if(m == n) {
    //     cout<<"1"<<endl;
    //     for(int i=1;i<n;i++) {
    //         cout<<i<<" "<<i+1<<endl;
    //     }
    //     return;
    // }
    // cout<<"--"<<endl;
    int root = 1;
    int sum = 0;
    for(int i = n; i > 0; i--) {
        sum += i;
        if(sum >= m) {
            break;
        }
        root++;
    }
    // set<int> st;
    cout<<root<<endl;
    
}