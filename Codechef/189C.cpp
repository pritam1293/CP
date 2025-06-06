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
    int n;
    cin>>n;
    if(n == 2) {
        cout<<"1 2"<<endl;
        return;
    }
    cout<<"2 1 3 ";
    for(int i=4;i<=n;i += 2) {
        if(i+1 <= n) {
            cout<<i+1<<" "<<i<<" ";
        }
        else {
            cout<<i;
        }
    }
    cout<<endl;
}