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

bool check(int rad, int n, int m, vector<int> &a, vector<int> &b) {
    vector<bool> vis(n, false);

    int p = 0;
    for(int i=0;i<m && p<n;i++) {
        while(p < n && a[p] >= b[i] - rad && a[p] <= b[i] + rad) {
            vis[p] = true;
            p++;
        }
    }

    for(int i=0;i<n;i++) {
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
    vector<int> b(m);
    for(int i=0;i<m;i++) {
        cin>>b[i];
    }
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int ans = 0;

    int st = 0, end = 1e9;

    while(st <= end) {
        int mid = (st + end) / 2;
        if(check(mid, n, m, a, b)) {
            ans = mid;
            end = mid-1;
        }
        else {
            st = mid+1;
        }
    }
    cout<<ans<<endl;
}