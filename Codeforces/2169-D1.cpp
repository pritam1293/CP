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

int check(int x, int y, int mid) {
    for(int i = 0; i < x; i++) {
        mid -= mid/y;
    }
    return mid;
}

void solve() {
    int x, y, k;
    cin>>x>>y>>k;
    int low = 1, high = 1e12, ans = -1;
    while(low <= high) {
        int mid = (low + high) / 2ll;
        int r = check(x, y, mid);
        if(r >= k) {
            ans = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    if(ans != -1 && check(x, y, ans) == k) {
        cout<<ans<<endl;
    }
    else {
        cout<<-1<<endl;
    }
}