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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    bool logged = false;
    int cnt = 0;
    for(int i=0;i<n;i++) {
        string s;
        cin>>s;
        if(s == "login") logged = true;
        else if(s == "logout") logged = false;

        if(!logged && s == "private") cnt++; 
    }
    cout<<cnt<<endl;
}