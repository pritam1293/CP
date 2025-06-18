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

bool check(string &s, int n) {
    set<char> st;
    for(int i=0;i<n;i++) {
        if(st.find(s[i]) != st.end() && i != n-1) {
            return true;
        }
        st.insert(s[i]);
    }
    return false;
}

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(check(s, n)) {
        cout<<"Yes"<<endl;
        return;
    }
    reverse(s.begin(), s.end());
    if(check(s, n)) {
        cout<<"Yes"<<endl;
        return;
    }
    cout<<"No"<<endl;
}