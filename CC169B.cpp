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
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++) {
        int j = i;
        int cnt1 = 0 , cnt2 = 0;
        while(j) {
            if(j % 2) cnt1++;
            j /= 2;
        }
        while(a[i]) {
            if(a[i] % 2) cnt2++;
            a[i] /= 2;
        }
        if(cnt1 != cnt2) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
