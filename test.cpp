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

int gcd(int a, int b) {
    return __gcd(a, b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int count(int mid, int a, int b, int c) {
    int ab = lcm(a, b);
    int bc = lcm(b, c);
    int ca = lcm(c, a);
    int abc = lcm(ab, c);
    return (mid / a) + (mid / b) + (mid / c) - (mid / ab) - (mid / bc) - (mid / ca) + (mid / abc);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int base = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2) base += a[i];
        else base -= a[i];
    }

    int ans = base;
    long long bestOdd = LLONG_MIN; // for odd indices
    long long maxOddIdx = -1, maxEvenIdx = -1;

    for (int i = 1; i <= n; i++) {
        if (i % 2) {
            // odd index candidate
            bestOdd = max(bestOdd, -2*a[i] - i);
            maxOddIdx = max(maxOddIdx, (long long)i);
        } else {
            // even index candidate for odd-even swap
            if (bestOdd != LLONG_MIN) {
                long long cand = base + (2*a[i] + i) + bestOdd;
                ans = max(ans, cand);
            }
            maxEvenIdx = max(maxEvenIdx, (long long)i);
        }
    }

    // also consider same-parity swaps: just gain (r-l)
    if (maxOddIdx > 1) ans = max(ans, base + (maxOddIdx - 1));
    if (maxEvenIdx > 2) ans = max(ans, base + (maxEvenIdx - 2));

    cout << ans << "\n";
}