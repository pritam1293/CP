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

// int fnc(int n) {
//     if(n == 1) return 1;
//     int cnt = 0;
//     while(n != 1) {
//         if(n % 2 == 1) n++;
//         n /= 2;
//         cnt++;
//     }
//     return cnt;
// }

void solve() {
    int n;
    cin>>n;
    int x = log2(n) + 1;
    cout<< 2 * x + 1 <<endl;
}