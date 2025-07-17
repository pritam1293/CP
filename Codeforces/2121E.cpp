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
    string l, r;
    cin>>l>>r;
    if(l == r) {
        cout<< 2 * l.size() <<endl;
        return;
    }
    int ptr = 0;
    while(ptr < l.size() && l[ptr] == r[ptr]) ptr++;
    if(l[ptr] + 1 < r[ptr]) {
        cout<< 2 * ptr <<endl;
    }
    else {
        int ans = 2 * ptr + 1;
        for(int i = ptr+1 ; i < l.size(); i++){
            if(l[i] == '9' && r[i] == '0') ans++;
            else break;
        }
        cout<<ans<<endl;
    }
}