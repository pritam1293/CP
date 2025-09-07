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
    int n, k;
    cin>>n>>k;
    int base = 1 << n;
    if(k % base == 0) {
        cout<<"0"<<endl;
        int a = k / base;
        while(base--) {
            cout<<a<<" ";
        }
    }
    else {
        cout<<"1"<<endl;
        vector<int> ans = {k};
        for(int i = 0; i < n; i++) {
            vector<int> next;
            for(auto& val : ans) {
                int a = val / 2;
                int b = val - a;
                next.push_back(a);
                next.push_back(b);
            }
            ans = next;
        }
        for(auto& e : ans) {
            cout<<e<<" ";
        }
    }
}