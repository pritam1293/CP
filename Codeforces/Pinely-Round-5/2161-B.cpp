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
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

int getDiff(set<int> &st) {
    if(st.empty()) return 0;
    return *st.rbegin() - *st.begin();
}

void solve() {
    int n;
    cin>>n;
    set<int> x, y, a, b;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char c;
            cin>>c;
            if(c == '#') {
                x.insert(i);
                y.insert(j);
                a.insert(i+j);
                b.insert(i-j);
            }
        }
    }
    if((getDiff(x) <= 1 && getDiff(y) <= 1) || getDiff(a) <= 1 || getDiff(b) <= 1) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
}