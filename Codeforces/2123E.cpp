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
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> cnt(n+1);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        cnt[a[i]]++;
    }
    vector<int> segment(n+3);
    for(int k = 0; k <= n; k++) {
        if(cnt[k] <= n-k) {
            segment[cnt[k]]++;
            segment[n-k+1]--;
        }
        if(cnt[k] == 0) break;
    }
    int val = 0;
    for(int k = 0; k <= n; k++) {
        val += segment[k];
        cout<<val<<" ";
    }
    cout<<endl;
}