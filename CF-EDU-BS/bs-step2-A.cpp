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

bool isFit(long long a, long long b, long long n, long long x) {
    long long cnt1 = x/a;
    long long cnt2 = x/b;
    long long cnt = cnt1 * cnt2;
    return cnt >= n;
}

void solve() {
    long long a,b,n;
    cin>>a>>b>>n;
    long long low = 0, high = 1;
    while(!isFit(a, b, n, high)) {
        high *= 2ll;
    }
    int ans = high;
    while(high > low + 1) {
        long long mid =  (low + high) / 2;

        if(isFit(a, b, n, mid)) {
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    cout<<high<<endl;
}