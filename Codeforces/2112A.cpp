#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
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
    int n, x, y;
    cin>>n>>x>>y;
    for(int i=1;i<=300;i++) {
        if(abs(n-x) > abs(i-x) && abs(n-y) > abs(i-y)) {
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
}