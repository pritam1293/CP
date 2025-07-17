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
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    int one = 0;
    for(auto& ch : s) {
        if(ch == '1') one++; 
    }
    if(one == 0 || one == n) {
        if(k == n/2) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
        return;
    } 
    int mx = max(one, n-one);
    int mn = min(one, n-one);
    int diff = (mx - mn)/2;
    if(k < diff) {
        cout<<"NO"<<endl;
        return;
    }
    k -= diff;
    if(k % 2 == 0) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
}