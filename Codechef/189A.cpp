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

static bool compare(pair<int,int> &a, pair<int,int> &b) {
    return a.second < b.second;
}

void solve() {
    int n, c;
    cin>>n>>c;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i].first;
    }
    for(int i=0;i<n;i++) {
        cin>>a[i].second;
    }
    sort(a.begin(), a.end(), compare);
    // for(auto& [f, s] : a) {
    //     cout<<f<<" "<<s<<endl;
    // }
    // cout<<endl;
    set<int> st;
    int ans = 0;
    int cnt = 0;
    int sum = 0;
    for(int i=0;i<n;i++) {
        if(st.count(a[i].first)) continue;
        st.insert(a[i].first);
        cnt++;
        sum += a[i].second;
        ans = max(ans, c * cnt - sum);
    }
    cout<<ans<<endl;
}