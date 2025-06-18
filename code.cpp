#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    cout<<40<<endl;
    int n = 80;
    while(n) {
        cout<<n<<" ";
        n -= 2;
    }
    cout<<endl;
    cout<<40<<endl;
    n = 79;
    while(n >= 1) {
        cout<<n<<" ";
        n -= 2;
    }
}
