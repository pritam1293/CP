#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    // freopen("../../9.in", "r", stdin);
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
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    stack<int> st;
    vector<int> left(n);
    for(int i=0;i<n;i++) {
        while(!st.empty() && st.top() <= a[i]) st.pop();
        left[i] = st.size();
        st.push(a[i]);
    }
    for(auto& val : left) {
        cout<<val<<" ";
    }
    while(!st.empty()) st.pop();
    vector<int> right(n);
    for(int i=n-1;i>=0;i--) {
        while(!st.empty() && st.top() <= a[i]) st.pop();
        right[i] = st.size();
        st.push(a[i]);
    }
    // reverse(right.begin(), right.end());
    cout<<endl;
    for(auto& val : right) {
        cout<<val<<" ";
    }
    // int ans = 0;
    // for(int i=0;i<n;i++) {
    //     ans = max(ans, left[i] + right[i]);
    // }
    // cout<<ans<<endl;
}