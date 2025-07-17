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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    if(a > c) {
        cout<<"Yes"<<endl;
        return;
    }
    if(a == c && b >= d) {
        cout<<"Yes";
        return;
    }
    cout<<"No"<<endl;
}