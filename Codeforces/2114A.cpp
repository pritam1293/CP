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
    string s;
    cin>>s;
    int n = stoi(s);
    int root = sqrt(n);
    if(root * root != n) {
        cout<<"-1"<<endl;
        return;
    }
    for(int i=0;i<=root;i++) {
        int num = (i * i) + (root-i) * (root-i);
        if(num == n) {
            cout<<i<<" "<<root-i<<endl;
            return;
        }
    }
    cout<<"-1"<<endl;
}