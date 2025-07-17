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
    string s,t;
    cin>>n>>s>>t;
    int cnt = 0 , one = 0;
    for(int i=0;i<n;i++) {
        if(s[i] == '1' && t[i] == '1') one++;
        else if(s[i] != t[i]) cnt++;
    }
    if(one % 2 == 1) {
        cout<<"YES"<<endl;
    }
    else{
        if(cnt != 0) {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
