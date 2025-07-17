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

int cows(vector<int> &a, int n, int x) {
    int sum = 0;
    int cnt = 1;
    for(int i=1;i<n;i++) {
        int diff = a[i] - a[i-1];

        sum += diff;
        if(sum >= x) {
            cnt++;
            sum = 0;
        }
    }
    return cnt;
}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int low = INT_MAX;
    for(int i=1;i<n;i++) {
        low = min(low, a[i] - a[i-1]);
    }
    int high = a[n-1] - a[0];

    int ans = 0;
    while(low <= high) {
        int mid = low + (high - low) / 2;

        int cnt = cows(a, n, mid);

        if(cnt >= k) {
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    cout<<ans<<endl;
}