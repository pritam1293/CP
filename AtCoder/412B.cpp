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
    string s, t;
    cin>>s>>t;
    // cout<<t<<endl;
    for(int i=1;i<s.size();i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            bool flag = false;
            for(int j = 0; j < t.size(); j++) {
                if(t[j] == s[i-1]) {
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                cout<<"No"<<endl;
                return;
            }
        }
    }
    cout<<"Yes";
}