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
    int n,k;
    cin>>n>>k;
    int x = k-n+2;
    if(x < 1) {
        cout<<-1<<endl;
        return;
    }
    cout<<x<<" "<<(2*x)<<" ";
    int num = 2*x;
    for(int i=2;i<n;i++) {
        num++;
        cout<<num<<" ";
    }
    cout<<endl;
}