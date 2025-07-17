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

int left_idx, right_idx;

bool check(vector<int> &a, int n, int d, double x) {
    vector<double> psum(n);
    vector<double> pmin(n);
    vector<int> idx(n);

    psum[0] = a[0] - x;
    pmin[0] = a[0] - x;

    for(int i=1;i<n;i++) {
        psum[i] = psum[i-1] + a[i] - x;

        if(psum[i] <= pmin[i-1]) {
            pmin[i] = psum[i];
            idx[i] = i;
        }
        else {
            pmin[i] = pmin[i-1];
            idx[i] = idx[i-1];
        }
    }

    for(int i=d-1;i<n;i++) {
        if(psum[i] >= 0) {
            left_idx = 0;
            right_idx = i;
            return true;
        }
        if(i-d >= 0 && psum[i] >= pmin[i-d]) {
            left_idx = idx[i-d]+1;
            right_idx = i;
            return true;
        }
    }
    return false;
}

void solve() {
    int n,d;
    cin>>n>>d;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

    double low = 0, high = 110;
    for(int i=0;i<110;i++) {
        double mid = (low + high) / 2;

        if(check(a, n, d, mid)) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    cout<<left_idx + 1<<" "<<right_idx + 1;
}