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
    int k, n;
    cin>>k>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    int l = 0, r = n-1;
    int mx = a[r], mn = a[l];
    bool flag = true;
    for(int i=0;i<k;i++) {
        if(flag) {
            cout<<mx<<" "<<mn<<" "<<mx<<" "<<mn<<" "<<mx<<" "<<mn<<endl;
        }
        else {
            cout<<mn<<" "<<mx<<" "<<mn<<" "<<mx<<" "<<mn<<" "<<mx<<endl;
        }
        if(!flag) {
            l++;r--;
        }
        flag = !flag;
        mx = a[r];
        mn = a[l];
    }
}