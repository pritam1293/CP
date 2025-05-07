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

bool isPossible(vector<int> &a, int k, double x) {
    if(x == 0) return true;
    int cnt = 0;
    for(int i=0;i<a.size();i++) {
        cnt += (int)(a[i] / x);
    }
    return cnt >= k;
}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    int maxm = -1;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        maxm = max(maxm, a[i]);
    }
    double low = 0, high = maxm;
    int op = 50;
    while(op--) {
        double mid = (low + high) / 2;

        if(isPossible(a, k, mid)) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    cout<<setprecision(7)<<low<<endl;
}