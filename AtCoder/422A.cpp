#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t=1;
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    string s;
    cin>>s;
    
    int dash = s.find('-');
    int i = stoi(s.substr(0, dash));
    int j = stoi(s.substr(dash + 1));
    
    if (j < 8) {
        cout<<i<<"-"<< j+1 <<endl;
    } 
    else if (i < 8) {
        cout<<i+1<<"-1"<<endl;;
    }
    else {
        cout <<"8-8";
    }
}