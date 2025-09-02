#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int t=1;
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

vector<int> tree, a;
int inf  = 1e9 + 7;

void build(int low, int high, int pos) {
    if(low == high) {
        tree[pos] = a[low];
        return;
    }
    int mid = (low + high) / 2;
    build(low, mid, 2*pos + 1);
    build(mid+1, high, 2*pos + 2);
    tree[pos] = min(tree[2*pos + 1], tree[2*pos + 2]);
}

int query(int qlow, int qhigh, int low, int high, int pos) {
    if(low >= qlow && high <= qhigh) return tree[pos];//total overlap
    if(qlow > high || low > qhigh) {
        return inf;
    }
    int mid = (low + high) / 2;
    return min(query(qlow, qhigh, low, mid, 2*pos + 1), query(qlow, qhigh, mid+1, high, 2*pos + 2));
}

void solve() {
    int n, q;
    cin>>n>>q;
    a = vector<int>(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    tree = vector<int>(4*n);
    build(0, n-1, 0);
    while(q--) {
        int i, j;
        cin>>i>>j;
        i--;j--;
        cout<<query(i, j, 0, n-1, 0)<<endl;
    }
}