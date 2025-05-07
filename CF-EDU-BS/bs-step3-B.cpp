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

int segments(vector<long long> &a, long long mid, int k) {
    int cnt = 0;
    long long sum = 0;
    for(int i=0;i<a.size();i++) {
        if(sum + a[i] <= mid) {
            sum += a[i];
        }
        else {
            sum = a[i];
            cnt++;
        }
    }
    if(sum != 0) cnt++;
    return cnt;
}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<long long> a(n);
    long long sum = 0;
    long long maxm = 0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        sum += a[i];
        maxm = max(maxm, a[i]);
    }

    long long low = maxm, high = sum;
    long long ans = 1e15;
    while(low <= high) {
        long long mid = (low + high) / 2;

        int cnt = segments(a, mid, k);
        if(cnt <= k) {
            ans = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    cout<<ans<<endl;
}