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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(m);
    for(int i=0;i<m;i++) {
        cin>>a[i];
    }
    vector<int> q(k);
    for(int i=0;i<k;i++) {
        cin>>q[i];
    }

    if(k == n) {
        for(int i=0;i<m;i++) {
            cout<<1;
        }
        cout<<endl;
        return;
    }

    if(k < n-1) {
        for(int i=0;i<m;i++) {
            cout<<0;
        }
        cout<<endl;
        return;
    }

    vector<bool> ans(n+1 , false);

    for(int i=0;i<k;i++) {
        ans[q[i]] = true;
    } 
    for(int i=0;i<m;i++) {
        if(ans[a[i]]) {
            cout<<0;
        }
        else {
            cout<<1;
        }
    }
    cout<<endl;
    // cout<<"thinking"<<endl;
    
}
