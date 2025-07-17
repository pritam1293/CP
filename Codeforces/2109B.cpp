#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
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

int count(int n) {
    int cnt = 0;
    while(n != 1) {
        if(n % 2) n++;
        n /= 2;
        cnt++;
    }
    return cnt;
}

void solve() {
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int mina = min(a, n-a+1);
    int minb = min(b, m-b+1);

    cout<< 1 + min(count(mina) + count(m), count(minb) + count(n)) <<endl;
}