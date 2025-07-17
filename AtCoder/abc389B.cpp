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

long long fact(long long n) {
    long long num = 1;
    for(int i=1;i<=n;i++) {
        num *= i;
    }
    return num;
}

void solve() {
    long long x;
    cin>>x;
    for(long long i=1;i<50;i++) {
        if(fact(i) == x) {
            cout<<i<<endl;
            return;
        }
    }
}
