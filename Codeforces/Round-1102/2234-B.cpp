#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    if (!freopen("../../input.txt", "r", stdin)) {
        cerr << "Failed to open input.txt\n";
    }
    if (!freopen("../../output.txt", "w", stdout)) {
        cerr << "Failed to open output.txt\n";
    }
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    if(n == 10) {
        cout<<"-1"<<endl;
    }
    if(n % 12 == 10) {
        cout<<"22 "<< n-22 <<endl;
    }
    else {
        cout<< n%12 <<" "<< n - n%12 <<endl;
    }
}