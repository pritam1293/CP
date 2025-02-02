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

bool check(string &s,int i) {
    if(i >= 0 && i+3 < s.size() && s.substr(i,4) == "1100") return true;
    return false;
}

void solve() {
    string s;
    cin>>s;
    int n = s.size();
    int cnt = 0;
    for(int i=0;i<n-3;i++) {
        if(s.substr(i,4) == "1100") cnt++;
    }
    int q;
    cin>>q;
    while(q--) {
        int i;
        char v;
        cin>>i>>v;
        i--;//for indexing
        if(s[i] != v) {
            //check if cnt is getting reduced
            if(s[i] == '1') {
                if((check(s,i) || check(s,i-1)) && cnt > 0) cnt--;
            }
            else{
                if((check(s,2) || check(s,i-3)) && cnt > 0) cnt--;
            }
            //check if cnt is getting any increment
            if(v == '1') {
                if(check(s,i) || check(s,i-1)) cnt++;
            }
            else {
                if(check(s,i-2) || check(s,i-3)) cnt++;
            }
            s[i] = v;
        }
        cout<<(cnt > 0 ? "YES" : "NO")
    }
}
