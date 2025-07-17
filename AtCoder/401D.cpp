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
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;

    for(char c : s) {
        if(c == 'o') k--;
    }

    for(int i=0;i<n;i++) {
        if(s[i] == '?' && ((i-1 >= 0 && s[i-1] == 'o') || (i+1 < n && s[i+1] == 'o'))) {
            s[i] = '.';
        }
    }
    int cnt = 0, c = 0;
    for(int i=0;i<n;i++) {
        if(s[i] == '?') c++;
        else {
            cnt += (c+1)/2;
            c = 0;
        }
    }
    cnt += (c+1)/2;
    cout<<cnt<<endl;
    if(cnt == k) {
        for(int i=0;i<n;i++) {
            if(s[i] == '?') s[i] = 'o';
        }
    }
    cout<<s<<endl;
}