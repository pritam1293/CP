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
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    int odd = 0, even = 0;
    set<int> st;
    st.insert(0);
    for(int i = 0; i < n; i++) {
        if(i % 2) {
            odd += a[i];
        }
        else {
            even += a[i];
        }
        int diff = odd - even;
        if(st.find(diff) != st.end()) {
            cout<<"YES"<<endl;
            return;
        }
        st.insert(diff);
    }
    cout<<"NO"<<endl;
}