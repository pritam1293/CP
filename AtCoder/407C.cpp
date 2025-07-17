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
    string s;
    cin>>s;
    int n = s.size();
    int ans = n;
    int prev = 0;
    for(int i = n-1; i>= 0; i--) {
        int num = s[i] - '0';
        num -= prev;
        num = (num -prev + 10) % 10;
        ans += num;
        prev = s[i] - '0';
    }
    cout<<ans;
}