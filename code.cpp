#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

static bool compare(int a, int b) {
    return a < b;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a.begin(), a.end(), compare);
    for(auto val : a) {
        cout<<val<<" ";
    }
    cout<<(int)'0'<<endl;

    n = 99;
    while(n) {
        cout<< n%2 << " ";
        n /= 2;
    }
}
