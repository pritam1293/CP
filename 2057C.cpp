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
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int l,r;
    cin>>l>>r;
    int n = l , m = r;
    int a = 0 , b = 0;

    bool same = true;
    while(same) {
        int p1 = (l == 0 ? 0 : log2(l));
        int p2 = log2(r);

        if(p1 == p2) {
            int num = pow(2,p1);
            a += num;
            b = a;
            l -= num;
            r -= num;
        } 
        else {
            same = false;
        }
    }

    int p = log2(r);
    int num = pow(2,p);
    a += num;
    b += num-1;
    int c;
    for(int i=n;i<=m;i++) {
        c = i;
        if(c != a && c != b) {
            break;
        }
    }
    // cout<<((a^b) + (b^c) + (c^a))<<endl;
    cout<<a<<" "<<b<<" "<<c<<endl;
}
