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

bool meet(double time, int n, vector<double> &a, vector<double> &v, vector<vector<double>> &interval) {
    for(int i=0;i<n;i++) {
        interval[i][0] = a[i] - time * v[i];
        interval[i][1] = a[i] + time * v[i];
    }
    // sort(interval.begin(), interval.end());

    double left = interval[0][0], right = interval[0][1];

    for(int i=1;i<n;i++) {
        left = max(left, interval[i][0]);
        right = min(right, interval[i][1]);
    }
    return left <= right;
}

void solve() {
    int n;
    cin>>n;
    vector<double> a(n),v(n);
    for(int i=0;i<n;i++) {
        cin>>a[i]>>v[i];
    }

    double low = 0, high = 1e10;
    vector<vector<double>> interval(n, vector<double>(2));
    for(int i=0;i<100;i++) {
        double mid = (low + high) / 2;

        if(meet(mid, n, a, v, interval)) {
            high = mid;
            // cout<<"ex"<<endl;
        }
        else {
            low = mid;
        }
    }
    cout<<setprecision(8)<<high<<endl;
}