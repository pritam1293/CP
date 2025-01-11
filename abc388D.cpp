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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    vector<int> neg(n+5);

    int add = 0 , give = n-1;

    int sub = 0;

    for(int i=0;i<n;i++) {
        sub += neg[i];

        int num = a[i] + add - sub;

        if(num - give < 0 && i+num+1 < n+5) {
            neg[i+num+1] += 1;
        }

        a[i] += add;
        a[i] -= sub;
        a[i] -= give;

        add++;
        give--;
        cout<<max(0,a[i])<<" ";
    }
}
