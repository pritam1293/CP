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

bool isPossible(vector<vector<long long>> &a, long long &n, long long &m, long long &time) {
    long long ballons = 0;
    for(int i=0;i<n;i++) {
        long long t = a[i][0];
        long long z = a[i][1];
        long long y = a[i][2];

        long long t_dash = z * t + y;
        long long z_dash = time / t_dash;

        ballons += z_dash * z;

        long long rem_time = time - z_dash * t_dash;
        long long cnt = min(z, rem_time / t);
        
        ballons += cnt;
    }
    return ballons >= m;
}

void solve() {
    long long m,n;
    cin>>m>>n;
    vector<vector<long long>> a(n, vector<long long>(3));
    for(int i=0;i<n;i++) {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }

    long long low = 0, high = 1e9;
    long long time = high;

    while(low <= high) {
        long long mid = low + (high - low) / 2;

        if(isPossible(a, n, m, mid)) {
            time = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    cout<<time<<endl;

    for(int i=0;i<n;i++) {
        long long ballons = 0;

        long long t = a[i][0];
        long long z = a[i][1];
        long long y = a[i][2];

        long long t_dash = z * t + y;
        long long z_dash = time / t_dash;

        ballons += z_dash * z;

        long long rem_time = time - z_dash * t_dash;
        long long cnt = min(z, rem_time / t);
        
        ballons += cnt;
        if(ballons <= m) {
            cout<<ballons<<" ";
        }
        else {
            cout<<max(0ll, m)<<" ";
        }
        m -= ballons;
    }
    cout<<endl;
}