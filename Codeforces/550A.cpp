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

int first(string &s, string tar, int n) {
    for(int i = 1; i < n; i++) {
        if(s[i-1] == tar[0] && s[i] == tar[1]) return i-1;
    }
    return -1;
}

int last(string &s, string tar, int n) {
    for(int i = n-2; i >= 0; i--) {
        if(s[i] == tar[0] && s[i+1] == tar[1]) return i;
    }
    return -1;
}

void solve() {
    string s;
    cin>>s;
    int n = s.size();
    int i = first(s, "AB", n);
    int j = last(s, "BA", n);
    if(i != -1 && j != -1 && abs(i-j) > 1) {
        cout<<"YES"<<endl;
        return;
    }
    i = first(s, "BA", n);
    j = last(s, "AB", n);
    if(i != -1 && j != -1 && abs(i-j) > 1) {
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}