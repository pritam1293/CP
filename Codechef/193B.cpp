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
    int a, b;
    cin>>a>>b;
    if(a == 0) {
        cout<<"No"<<endl;
        return;
    }
    if(b == 0) {
        cout<<"Yes"<<endl;
        return;
    }
    if(b % a != 0) {
        cout<<"No"<<endl;
    }
    else {
        cout<<"Yes"<<endl;
    }
}