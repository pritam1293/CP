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

bool isPossible(vector<long long> &a, int n, int k, long long x) {//x = no. of councils
    long long sum = 0;
    for(int i=0;i<n;i++) sum += min(x, a[i]);

    if(sum >= x * (long long)k) return true;
    return false;
}

void solve() {
    int k,n;
    cin>>k>>n;
    vector<long long> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

    long long low = 0, high = 1e12;
    long long ans = 0;
    
    while(low <= high) {
        long long mid = low + (high - low) / 2;

        if(isPossible(a, n, k, mid)) {
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    cout<<ans<<endl;
}