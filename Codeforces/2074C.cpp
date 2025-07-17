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
    int a;
    cin>>a;
    int b = 1;
    while(b < a-1) {
        b++;
        // cout<<"b: "<<b<<endl;
        int c = (a^b);
        if(a+b > c && b+c > a && c+a > b) {
            cout<<b<<endl;
            return;
        }
        b--;
        b *= 2;
    }
    cout<<"-1"<<endl;

    // 2^n + 1 
}