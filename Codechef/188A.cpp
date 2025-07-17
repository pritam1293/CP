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
    int one = 0, two = 0;
    for(int i=0;i<n;i++) {
        if(a[i] % 3 == 0) {
            cout<<"YES"<<endl;
            return;
        }
        if(a[i] % 3 == 1) one++;
        else two++;
        if(one >= 3 || two >= 3 || (one >= 1 && two >= 1)) {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}   