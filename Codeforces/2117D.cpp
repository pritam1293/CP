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
    int diff = a[1] - a[0];
    bool flag = true;
    for(int i=1;i<n;i++) {
        if(a[i] - a[i-1] != diff) {
            flag = false;
            break;
        }
    }
    if(!flag) {
        cout<<"NO"<<endl;
        return;
    }
    int newdiff = a[0] - diff;
    if(newdiff < 0 || newdiff % (n+1) != 0) {
        cout<<"NO"<<endl;
        return;
    }
    int y = newdiff / (n+1);
    int x = y + diff;
    if(x >= 0) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
}