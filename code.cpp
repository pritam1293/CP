#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

bool canAchieve(vector<int> A, vector<int> B, int M) {
    int N = A.size();
    int totalTwos = 0;

    for (int i = 0; i < N; ++i) {
        int need = max(0LL, M - A[i]);        // how many +1s needed
        int ones = min(B[i], need);
        A[i] += ones;
        int rem = B[i] - ones;
        totalTwos += rem;                     // each rem can be used as +2 for others
    }

    for (int i = 0; i < N; ++i) {
        if (A[i] > M) return false;
    }

    int extra = 0;
    for (int i = 0; i < N; ++i) {
        extra += max(0LL, M - A[i]);
    }

    return totalTwos * 2 >= extra;
}


void solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int &x : A) cin >> x;
    for (int &x : B) cin >> x;

    int lo = *max_element(A.begin(), A.end()), hi = 1e18, ans = hi;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (canAchieve(A, B, mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << '\n';
}
