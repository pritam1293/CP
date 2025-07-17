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

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    int i = 0, j = 0;
    long long ans = 0;
    while(i < n && j < m) {
        while(i < n && j < m && a[i] < b[j]) {
            i++;
        }
        while(i < n && j < m && b[j] < a[i]) {
            j++;
        }
        long long cnt1 = 0, cnt2 = 0;
        int num = -1;
        if(i < n) num = a[i];
        while(i < n  && a[i] == num) {
            cnt1++;
            i++;
        }
        while(j < m && b[j] == num) {
            cnt2++;
            j++;
        }
        ans += cnt1 * cnt2;
    }
    cout<<ans<<endl;
}