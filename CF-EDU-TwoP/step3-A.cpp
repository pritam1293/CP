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
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    int sum = 0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        sum += a[i];
    }
    int songs = k / sum;
    k %= sum;
    songs *= n;

    if(k == 0) {
        cout<<"1 "<<songs<<endl;
        return;
    }

    for(int i=0;i<n;i++) {
        a.push_back(a[i]);
    }   
    sum = 0;
    int cnt = INT_MAX;
    int l = 0;
    int idx = 0;
    for(int r = 0; r < 2*n; r++) {
        sum += a[r];
        while(sum - a[l] >= k) {
            sum -= a[l];
            l++;
        }
        if(sum >= k && cnt > r-l+1) {
            cnt = r-l+1;
            idx = l;
        }
    }
    cout<< (idx % n) + 1  << " " << cnt + songs <<endl;
}   