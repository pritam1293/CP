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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<int> b(m);
    multiset<int> st;
    for(int i = 0; i < n; i++) {
        int a;
        cin>>a;
        st.insert(a);
    }   
    for(int i = 0; i < m; i++) cin>>b[i];
    for(auto& e : b) {
        auto it = st.upper_bound(e);
        if(it == st.begin()) {
            cout<<"-1"<<endl;
        }
        else {
            it--;
            cout<< *it <<endl;
            st.erase(it);
        }
    }    
}