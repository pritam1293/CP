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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    set<int> st;
    map<int,int> mp;

    for(int i=1;i<=1259930;i++) {
        int num = i * i * i;
        st.insert(num);
        mp[num] = i;
    }
    for(int i=1;i<=1000015;i++) {
        int num = i * i * i + n;
        if(st.find(num) != st.end()) {
            cout<<mp[num]<<" "<<i<<endl;
            return;
        }
    }
    cout<<"-1"<<endl;
}