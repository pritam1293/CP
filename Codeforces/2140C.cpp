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

void solve() {
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        if(i % 2) sum += a[i];
        else sum -= a[i];
    }

    int ans = sum;
    int odd = LLONG_MIN;
    int oddi = -1, eveni = -1;
    for(int i = 1; i <= n; i++) {
        if(i % 2) {
            odd = max(odd, -2 * a[i] - i);
            oddi = max(oddi, i);
        }
        else {
            if (odd != LLONG_MIN) {
                int temp = sum + (2*a[i] + i) + odd;
                ans = max(ans, temp);
            }
            eveni = max(eveni, i);
        }
    }
    ans = max(ans, sum + oddi - 1);
    ans = max(ans, sum + eveni - 2);
    cout<<ans<<endl;
}