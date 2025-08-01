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
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(a[i] > a[j]) {
                cout<<"YES"<<endl;
                cout<<2<<endl;
                cout<<a[i]<<" "<<a[j]<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;
}