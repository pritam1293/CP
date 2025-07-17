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
    int n, q;
    cin>>n>>q;
    // cout<<n<<q<<endl;
    vector<int> op(q), p(q);
    vector<string> str(q);
    for(int i=0;i<q;i++) {
        cin>>op[i]>>p[i];
        if(op[i] == 2) {
            cin>>str[i];
            reverse(str[i].begin(), str[i].end());
            // cout<<str[i]<<endl;
        }
    }

    string ans;
    int i = 0;
    for(int t = q-1; t >= 0; t--) {
        if(op[t] == 1) {
            if(i == p[t]) i = 0;
        }
        else if(op[t] == 2) {
            if(i == p[t]) ans += str[t];
        }
        else {
            if(i == 0) i = p[t];
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
}