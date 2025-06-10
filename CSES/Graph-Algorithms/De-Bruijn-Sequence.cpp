#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}
set<string> st;
vector<int> edges;

void dfs(string node , int k, string &s) {
    for(int i=0;i<k;i++) {
        string str = node + s[i];
        if(st.find(str) == st.end()) {
            st.insert(str);
            dfs(str.substr(1), k, s);
            edges.push_back(i);
        }
    }
}

void solve() {
    int n;
    cin>>n;
    string s = "01";
    int k = 2;
    string node = string(n-1, s[0]);
    // cout<<node<<endl;
    dfs(node, k, s);

    string ans;
    int l = pow(k, n);
    for(int i=0;i<l;i++) {
        ans += s[edges[i]];
    }
    ans += node;
    cout<<ans<<endl;
}