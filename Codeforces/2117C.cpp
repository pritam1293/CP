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
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int cnt = 1;
    set<int> st, next;
    st.insert(a[0]);
    for(int i=1;i<n;i++) {
        if(st.count(a[i])) {
            st.erase(a[i]);
        }
        next.insert(a[i]);
        if(st.empty()) {
            cnt++;
            st = next;
            next.clear();
        }
    }
    cout<<cnt<<endl;
}