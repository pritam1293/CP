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

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    set<int> st;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') st.insert(i);
    }
    int one = 0, zero = 0, jump = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            one++;
            st.erase(i);
        }
        else {
            zero++;
        }
        if(zero > one) {
            if(st.empty()) continue;
            one++;
            zero--;
            int idx = *st.begin();
            st.erase(st.begin());
            s[i] = '1';
            s[idx] = '0';
            jump += abs(i - idx);
        }
    }
    cout<<min(2*one, n)<<" "<<jump<<endl;
}