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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

bool check(vector<int> &a, int m) {
    vector<int> vis(m+1, false);
    for(auto& val : a) {
        vis[val] = true;
    }
    for(int i=1;i<=m;i++) {
        if(!vis[i]) return false;
    }
    return true;
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    bool flag = false;
    int op = 0;
    while(!flag) {
        if(!check(a, m)) {
            flag = true;
            break;
        }
        a.pop_back();
        op++;
    }
    cout<<op<<endl;
}