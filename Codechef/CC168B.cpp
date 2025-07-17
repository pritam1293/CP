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

void solve() {
    long long n,x,k;
    cin>>n>>x>>k;
    string s;
    cin>>s;
    long long inv = 0;
    long long one = 0;
    for(int i=0;i<n;i++) {
        if(s[i] == '1') one++;
        else {
            inv += one;
        }
    }
    if(inv <= x && inv % k == 0){
        cout<<1<<endl;
    } 
    else {
        cout<<2<<endl;
    }
}
