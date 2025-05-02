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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    long long n;
    cin>>n;
    long long power = 1;
    long long ans = 0;
    for(int i=0;i<=60;i++) {
        long long num = n/power;
        long long cnt = (long long)sqrt(num);
        cout<<cnt<<endl;
        ans += cnt;
        power *= (long long)2;
    }
    cout<<endl;
    cout<<ans<<endl;
}