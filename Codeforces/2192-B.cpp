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
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int one = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] - '0') one++;
    }
    if((n-one) % 2) {
        cout<< n-one <<endl;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                cout<< i+1 <<" ";
            }
        }
        cout<<endl;
    }
    else if(one % 2 == 0) {
        cout<<one<<endl;
        if (one) {
            for(int i = 0; i < n; i++) {
                if(s[i] == '1') {
                    cout<< i+1 <<" ";
                }
            }
            cout<<endl;
        }
    }
    else {
        cout<<-1<<endl;
    }
}