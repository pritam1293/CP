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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n, c;
    cin>>n>>c;
    string s;
    cin>>s;
    int cnta = 0, cntb = 0, ans = 0, l = 0;
    int sum = 0;
    for(int r = 0; r < n; r++) {
        if(s[r] == 'a') cnta++;
        else if(s[r] == 'b') {
            cntb++;
            sum += cnta;
        }

        while(sum > c) {
            if(s[l] == 'a') {
                sum -= cntb;
                cnta--;
            }
            else if(s[l] == 'b') cntb--;
            l++;
        }
        ans = max(ans, r-l+1);
    }
    cout<<ans<<endl;
}