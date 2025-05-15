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
    int sum = 0;
    multiset<int> st;
    for(int i=0;i<5;i++) {
        int x;
        cin>>x;
        st.insert(x);
        sum += x;
    }
    int ans = 0;
    while(sum < 35) {
        sum += 10 - *st.begin();
        st.erase(st.begin());
        ans += 100;
    }
    cout<<ans<<endl;
}