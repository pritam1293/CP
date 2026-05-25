#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int a, b;
    cin>>a>>b;
    string yes = "Yes", no = "No";
    if(a == 1 && b == 7) {
        cout<<yes;
    }
    else if(a == 3 && b == 3) {
        cout<<yes;
    }
    else if(a == 5 && b == 5) {
        cout<<yes;
    }
    else if(a == 7 && b == 7) {
        cout<<yes;
    }
    else if(a == 9 && b == 9) {
        cout<<yes<<endl;
    }
    else {
        cout<<no;
    }
}