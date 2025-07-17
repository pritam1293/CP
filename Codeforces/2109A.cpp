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
    bool one = false;
    bool zero = false;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if(a[i] == 0) zero = true;
        else one = true;
    }
    if(!one || !zero) {
        cout<<"YES"<<endl;
        return;
    }
    for(int i=1;i<n;i++) {
        if(a[i] == 0 && a[i-1] == 0) {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}