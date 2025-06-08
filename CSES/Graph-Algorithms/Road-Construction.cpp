#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

vector<int> dsu;
int parent(int x) {
    if(dsu[x] < 0) return x;
    return dsu[x] = parent(dsu[x]);
}

void merge(int a, int b) {
    int x = parent(a), y = parent(b);
    if(x != y) {
        if(dsu[x] < dsu[y]) {
            dsu[x] += dsu[y];
            dsu[y] = x;
        }
        else {
            dsu[y] += dsu[x];
            dsu[x] = y;
        }
    }
}

void solve() {
    int n, m;
    cin>>n>>m;
    dsu = vector<int>(n+1, -1);
    set<int> st;
    int mx = 0;
    int cnt = n;
    for(int i=0;i<m;i++) { 
        int a, b;
        cin>>a>>b;  
        if(parent(a) != parent(b)) {
            merge(a, b);
            parent(a);
            parent(b);

            int par = parent(a);
            mx = max(mx, abs(dsu[par]));
            cnt--;
        }
        cout<<cnt<<" "<<mx<<endl;
    }
}