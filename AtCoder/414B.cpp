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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    string s;
    for(int i = 0; i < n; i++) {
        string c;
        int f;
        cin>>c>>f;
        if(f > 100) {
            s = "Too Long";
            break;
        }
        while(f--) s += c;
    }
    if(s.size() > 100) s = "Too Long";
    cout<<s<<endl;
}