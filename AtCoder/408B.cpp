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
    int n;
    cin>>n;
    set<int> st;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        st.insert(x);
    }
    cout<<st.size()<<endl;
    for(auto& it : st) {
        cout<<it<<" ";
    }
}