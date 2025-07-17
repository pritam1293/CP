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
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    int sum = 0;
    int maxm = 0;
    int minm = INT_MAX;  
    for(int i=0;i<n;i++) {
        cin>>a[i];
        sum += a[i] % 2;
        maxm = max(maxm, a[i]);
        minm = min(minm, a[i]);
    }
    int cnt = 0;
    for(int val : a) {
        if(val == maxm) cnt++;
    }
    if(maxm - minm - 1 > k || (cnt > 1 && maxm - minm > k)) {
        cout<<"Jerry"<<endl;
    }
    else {
        if(sum % 2 == 1) {
            cout<<"Tom"<<endl;
        }
        else {
            cout<<"Jerry"<<endl;
        }
    }
}