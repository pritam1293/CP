#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n), prefix(n+1);
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
        prefix[i+1] = prefix[i] + arr[i];
    }
    for(int i = 1; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int a = prefix[i] % 3;
            int b = (prefix[j] - prefix[i]) % 3;
            int c = (prefix[n] - prefix[j]) % 3;
            a = (a + 3) % 3;
            b = (b + 3) % 3;
            c = (c + 3) % 3;
            if((a == b && b == c) || (a != b && b != c && c != a)) {
                cout<<i<<" "<<j<<endl;
                return;
            }
        }
    }
    cout<<"0 0"<<endl;
}