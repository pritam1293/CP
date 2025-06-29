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
    int a, b;
    cin>>a>>b;
    if(__gcd(a, b) != 1) {
        cout<<"0"<<endl;
        return;
    }
    if(a % 2 == b % 2 ) {
        if(__gcd(a+1, b) != 1 || __gcd(a, b+1) != 1) {
            cout<<"1"<<endl;
        }
        else {
            cout<<"2"<<endl;
        }
    }
    else {
        cout<<"1"<<endl;
    }
}