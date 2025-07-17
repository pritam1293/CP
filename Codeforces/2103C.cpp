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

bool check(vector<int> &a, int n) {
    int l = n;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        if(sum >= 0) {
            l = i;
            break;
        }
    }
    cout<<"l: "<<l<<endl;
    if(l >= n-2) return false;
    int r = n;
    sum = 0;
    for(int i = l+1; i < n; i++) {
        sum += a[i];
        if(sum >= 0) {
            r = i;
            break;
        }
    }
    cout<<"r: "<<r<<endl;
    cout<<endl;
    if(r >= n-1) return false;
    return true;
}

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        a[i] = a[i] <= k ? 1 : -1;
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int l = n, r = -1;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        if(sum >= 0) {
            l = i;
            break;
        }
    }
    sum = 0;
    for(int i = n-1; i >= 0; i--) {
        sum += a[i];
        if(sum >= 0) {
            r = i;
            break;
        }
    }
    if(l < r) {
        cout<<"YES"<<endl;
        return;
    }
    if(check(a, n)) {
        cout<<"YES"<<endl;
        return;
    }
    reverse(a.begin(), a.end());
    if(check(a, n)) {
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}