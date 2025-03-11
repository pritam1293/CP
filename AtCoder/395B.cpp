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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    string s;
    for(int i=0;i<n;i++) {
        s += "#";
    }
    vector<string> pat(n);
    int x = 0 , y = n-1;
    for(int i=0;i <= n/2;i++) {
        if(i % 2 == 0) {
            for(int j=x;j<=y;j++) {
                s[j] = '#';
            }
        }
        else {
            for(int j=x;j<=y;j++) {
                s[j] = '.';
            }
        }
        x++;y--;
        pat[i] = s;
     }
    int j = 0;
    for(int i=n-1;i>n/2;i--) {
        pat[i] = pat[j++];
    }
    for(string it : pat) {
        cout<<it<<endl;
    }
}