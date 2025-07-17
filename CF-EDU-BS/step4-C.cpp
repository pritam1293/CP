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

bool check(vector<double> &a, vector<double> &b, int n, int k, double x) {
    priority_queue<double> pq;
    for(int i=0;i<n;i++) {
        pq.push(a[i] - x * b[i]);
    }
    double sum = 0;
    while(k--) {
        sum += pq.top();
        pq.pop();
    }
    return sum >= 0;
}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<double> a(n);
    vector<double> b(n);
    for(int i=0;i<n;i++) cin>>a[i]>>b[i];

    double low = 0, high = 1e6;
    for(int i=0;i<40;i++) {
        double mid = (low + high) / 2;
        if(check(a, b, n, k, mid)) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    cout<<setprecision(8)<<low<<endl;
}