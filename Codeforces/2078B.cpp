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
    if(k % 2 == 0) {
        for(int i=0;i<n;i++) {
            if(i != n-2) {
                cout<< n-1 <<" ";
            }
            else {
                cout<< n <<" ";
            }
        }
    }
    else {
        for(int i=0;i<n;i++) {
            if(i != n-1) {
                cout<< n <<" ";
            }
            else {
                cout<< n-1 <<" ";
            }
        }
    }
    cout<<endl;
}