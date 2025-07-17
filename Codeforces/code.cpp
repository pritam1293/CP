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
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int m,k;
    cin>>m>>k;
    string s;
    cin>>s;
    int swiss = 0;
    for(int i=0;i<m;i++) {
        if(s[i] == 'S') swiss++;
    }
    if(swiss >= k || m >= k) {
        cout<<m<<endl;
        return;
    }
    cout<<m+k-swiss-1<<endl;
}
