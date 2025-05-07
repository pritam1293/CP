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
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    multiset<int> st;
    int l = 0;
    int cnt = 0;
    for(int r = 0; r < n; r++) {
        st.insert(a[r]);
        while(*st.rbegin() - *st.begin() > k) {
            auto it = st.find(a[l]);
            st.erase(it);
            l++;
        }
        cnt += (long long)(r-l+1);
    }
    cout<<cnt<<endl;
}