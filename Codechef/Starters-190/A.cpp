#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt = 0;
    for(auto& ch : s) {
        if(ch == '1') cnt++;
    }
    if(n - cnt > cnt) {
        cout<<"No"<<endl;
        return;
    }
    vector<bool> used(n, false);
    for(int i=0;i<n;i++) {
        if(s[i] == '0') {
            if(i-1 >= 0 && s[i-1] == '1' && !used[i-1]) used[i-1] = true;
            else if(i+1 < n && s[i+1] == '1' && !used[i+1]) used[i+1] = true;
            else {
                cout<<"No"<<endl;
                return;
            }
        }
    }
    cout<<"Yes"<<endl;
}