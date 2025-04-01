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
    int n,m;
    cin>>n>>m;
    string s;
    if(n > m) {
        s = "0110";
    }
    else{
        s = "1001";
    }
    n--;m--;
    while(n > 0 && m > 0) {
        if(s.back() == '1') {
            s += "10";
            m--;
        }
        else {
            s +="01";
            n--;
        }
    }

    while(m--) {
        s += "10";
    }
    while(n--){
        s += "01";
    }

    int len = s.size();
    int cnt = 0;

    for(int i=1;i<len;i++){
        if(s[i] != s[i-1]) cnt++;
    }
    cout<<cnt<<endl;
}