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
    int n,k;
    cin>>n>>k;
    if(n == k || k == 1) {
        if(n == 1) {
            cout<<"1"<<endl;
            cout<<"1"<<endl;
        }
        else {
            cout<<-1<<endl;
        }
        return;
    }
    // if(k == 2) {
    //     cout<<3<<endl;
    //     cout<<"1 2 3"<<endl;
    //     return;
    // }
    cout<<3<<endl;
    if((n-k)%2 == 0) {
        cout<<1<<" "<<k-1<<" "<<k+2<<endl;
    }
    else {
        cout<<1<<" "<<k<<" "<<k+1<<endl;
    }
}
