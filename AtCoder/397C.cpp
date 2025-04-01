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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    map<int,int> mp; 
    for(int i=0;i<n;i++) {
        cin>>a[i];
        mp[a[i]]++;
    }
    set<int> st;
    int ans = 0;
    for(int i=0;i<n;i++) {
        mp[a[i]]--;
        if(mp[a[i]] == 0) mp.erase(a[i]);
        st.insert(a[i]);

        ans = max(ans, (int)st.size() + (int)mp.size());
    }
    cout<<ans<<endl;
}