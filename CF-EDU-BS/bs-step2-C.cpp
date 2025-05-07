    //bs-step2-C.cpp
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

bool isPossible(int x, int y, int n, int t) {
    if(min(x,y) > t) return false;
    int cnt = 1;
    t -= min(x, y);
    cnt += t/x + t/y;
    return cnt >= n;
}

void solve() {
    int n, x, y;
    cin>>n>>x>>y;

    int low = 0, high = max(x,y) * n;
    int t = high;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(isPossible(x, y, n, mid)) {
            high = mid-1;
            t = mid;
        }
        else {
            low = mid+1;
        }
    }
    cout<<t<<endl;
}