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

void solve() {
    int n, q;
    cin>>n>>q;
    string s;
    cin>>s;
    int a = 0, b = 0;
    for(auto& c : s) {
        if(c == 'A') a++;
        else b++;
    }
    while(q--) {
        int x;
        cin>>x;
        if(b == 0) {
            cout<<x<<endl;
        }
        else {
            int cnt = 0;
            while(x) {
                for(auto& c : s) {
                    if(x == 0) break;
                    cnt++;
                    if(c == 'A') {
                        x--;
                    }
                    else {
                        x /= 2;
                    }
                }
            }
            cout<<cnt<<endl;
        }
    }
}