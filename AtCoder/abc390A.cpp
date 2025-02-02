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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    vector<int> a(5);
    for(int i=0;i<5;i++) {
        cin>>a[i];
    }
    vector<int> ans = {1,2,3,4,5};
    for(int i=1;i<5;i++) {
        swap(a[i-1],a[i]);
        if(a == ans) {
            cout<<"Yes"<<endl;
            return;
        }
        swap(a[i-1],a[i]);
    }
    cout<<"No"<<endl;
}
