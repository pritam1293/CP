#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i].first;
        a[i].second = i+1;
    }
    sort(a.rbegin(),a.rend());
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        arr[i] = a[i].second;
        // cout<<arr[i]<<" ";
    }
    // cout<<endl;
    int cnt = n;
    for(int i=1;i<n;i++) {
        if(abs(arr[i] - arr[i-1]) == 1) cnt--;
    }
    cout<<cnt<<endl;
}
