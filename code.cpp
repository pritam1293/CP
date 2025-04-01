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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

bool rec(string a, string b, int n, map<string, bool> &mp) {
    if(a == b) return mp[a + "#" + b] = true;
    if(a.size() == 1) return false;
    if(mp.find(a + "#" + b) != mp.end()) return mp[a + "#" + b];
    
    for(int k=1;k<n;k++) {
        bool cond1 = rec(a.substr(0, k), b.substr(n-k), k, mp) && 
                        rec(a.substr(k, n-k), b.substr(0, n-k), n-k, mp);
        bool cond2 = rec(a.substr(0, k), b.substr(0,k), k, mp) &&
                        rec(a.substr(k, n-k), b.substr(k, n-k), n-k, mp);
        
        if(cond1 || cond2) return mp[a + "#" + b] = true;
    }
    return mp[a + "#" + b] = false;
}

int isScramble(const string a, const string b) {
    if(a.size() != b.size()) return 0;
    
    int n = a.size();
    map<string, bool> mp;
    return rec(a, b, n, mp);
}


void solve() {
    string a = "phqtrnilf";
    string b = "ilthnqrpf";
    cout<<isScramble(a,b)<<endl;
}
