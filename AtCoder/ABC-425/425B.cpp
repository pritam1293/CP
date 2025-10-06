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
    int n;
    cin>>n;
    vector<int> a(n);
    set<int> st;
    for(int i = 1; i <= n; i++) {
        st.insert(i);
    }
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    for(auto& e : a) {
        if(e != -1) {
            if(st.find(e) == st.end()) {
                cout<<"No"<<endl;
                return;
            }
            else st.erase(e);
        }
    }
    cout<<"Yes"<<endl;
    for(auto& e : a) {
        if(e == -1) {
            cout<< *st.begin() <<" ";
            st.erase(st.begin());
        }
        else {
            cout<<e<<" ";
        }
    }
    cout<<endl;
}