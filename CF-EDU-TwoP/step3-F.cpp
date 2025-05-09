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
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n,m;
    cin>>n>>m;
    string s, cards;
    cin>>s>>cards;
    vector<int> freq(26), cnt(26);
    set<char> st;
    for(auto& c : cards) {
        cnt[c-'a']++;
        st.insert(c);
    }

    int l = 0;
    int ans = 0;
    for(int r = 0; r < n; r++) {
        if(st.find(s[r]) == st.end) {
            for(int j=0;j<26;j++) {
                freq[j] = 0;
            }
        }       
        else {
            freq[c-'a']++;
            
        }
    }
}