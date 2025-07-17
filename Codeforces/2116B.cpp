#include<bits/stdc++.h>
using namespace std;
void solve();
void calp();
int main() {
    calp();
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

vector<int> po(1000001, 1);

int mod = 998244353;

void calp() {
    int n = 1e6;
    for(int i=1;i<=n;i++) {
        po[i] = (po[i-1] * 2) % mod;
    }
}

void solve() {
    int n;
    cin>>n;
    vector<int> p(n), q(n), pp(n), pq(n), pm(n), qm(n);
    for(int i=0;i<n;i++) {
        cin>>p[i];
        pp[p[i]] = i;
        if(i > 0) pm[i] = max(p[i], pm[i-1]);
        else pm[i] = p[i];
    } 
    for(int i=0;i<n;i++) {
        cin>>q[i];
        pq[q[i]] = i;
        if(i > 0) qm[i] = max(q[i], qm[i-1]);
        else qm[i] = q[i];
    }

    for(int i=0;i<n;i++) {
        int num1 = max(pm[i], qm[i]);
        int num2;
        if(pm[i] > qm[i]) {
            int j = pp[num1];
            num2 = q[i - j];
        }
        else if(pm[i] < qm[i]) {
            int j = pq[num1];
            num2 = p[i - j];
        }
        else {
            int j1 = pp[num1];
            int k1 = i - j1;
            int n1 = (k1 >= 0 && k1 < n ? q[k1] : -1);
            int j2 = pq[num1];
            int k2 = i - j2;
            int n2 = (k2 >= 0 && k2 < n ? p[k2] : -1);
            num2 = max(n1, n2);
        }
        cout<< (po[num1] + po[num2]) % mod <<" ";
    }
    cout<<endl;
}