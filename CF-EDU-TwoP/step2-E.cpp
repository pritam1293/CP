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
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    vector<int> freq(100001);
    int l = 0;
    long long ans = 0;
    int cnt = 0;
    for(int r = 0; r < n; r++) {
        if(freq[a[r]] == 0) cnt++;
        freq[a[r]]++;
        
        while(cnt > k) {
            freq[a[l]]--;
            if(freq[a[l]] == 0) cnt--;
            l++;
        }
        ans += (long long)(r-l+1);
    }
    cout<<ans<<endl;
}