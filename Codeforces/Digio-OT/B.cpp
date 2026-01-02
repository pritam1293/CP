#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

string yes = "YES";
string no = "NO";

void solve() {
    string a, b;
    cin>>a>>b;
    bool ans = false;
    int n = a.size();
    for (int i = 0; i+1 < n; ++i) {
        if (a[i] == b[i] && a[i] == '0' && a[i + 1] == b[i + 1] && a[i + 1] == '1') {
            ans = true;
        }
    }
    if(ans) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
}