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

void solve() {
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        a[i] = i+1;
    }
    int shift = 0;
    while(q--) {
        int type;
        cin>>type;

        if(type == 1) {
            int p, x;
            cin>>p>>x;
            p--;
            a[(p + shift) % n] = x;
        }
        else if(type == 2) {
            int p;
            cin>>p;
            p--;
            cout<< a[(p + shift) % n] <<endl;
        }
        else {
            int k;
            cin>>k;
            shift = (shift + k) % n;
        }
    }
}