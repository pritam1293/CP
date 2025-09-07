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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

vector<int> a, tree, lazy;
int inf = 1e18 + 7;

void rangeUpdate(int ql, int qr, int val, int low, int high, int pos) {
    if(low > high) return;
    //lazy propagation at pos, if not processed process now
    if(lazy[pos] != 0) {
        tree[pos] += lazy[pos];
        if(low != high) {
            lazy[2*pos + 1] += lazy[pos];
            lazy[2*pos + 2] += lazy[pos];
        }
        lazy[pos] = 0;
    }

    //no overlap
    if(ql > high || qr < low) return;

    //fully overlap
    if(low >= ql && high <= qr) {
        tree[pos] += val;
        if(low != high) {
            lazy[2*pos + 1] += val;
            lazy[2*pos + 2] += val;
        }
        return;
    }

    //partial overlap
    int mid = (low + high) / 2;
    rangeUpdate(ql, qr, val, low, mid, 2*pos + 1);
    rangeUpdate(ql, qr, val, mid + 1, high, 2*pos + 2);
    tree[pos] = min(tree[2*pos + 1], tree[2*pos + 2]);
}

void buildTree(int low, int high, int pos) {
    if(low == high) {
        tree[pos] = a[low];
        return;
    }
    int mid = (low + high) / 2;
    buildTree(low, mid, 2*pos + 1);
    buildTree(mid+1, high, 2*pos + 2);
    tree[pos] = min(tree[2*pos + 1], tree[2*pos + 2]);
}

int rangeMin(int qlow, int qhigh, int low, int high, int pos) {
    if(low > high) return inf;

    //lazy propagation at pos, if not processed process now
    if(lazy[pos] != 0) {
        tree[pos] += lazy[pos];
        if(low != high) {
            lazy[2*pos + 1] += lazy[pos];
            lazy[2*pos + 2] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    //no overlap
    if(high < qlow || low > qhigh) {
        return inf;
    }
    //total overlap
    if(low >= qlow && high <= qhigh) {
        return tree[pos];
    }
    //partial overlap
    int mid = (low + high) / 2;
    return min(rangeMin(qlow, qhigh, low, mid, 2*pos + 1),
                rangeMin(qlow, qhigh, mid+1, high, 2*pos + 2));
}

void solve() {
    int n, q;
    cin>>n>>q;
    a = vector<int>(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    tree = vector<int>(4*n);
    lazy = vector<int>(4*n);
    buildTree(0, n-1, 0);
    while(q--) {
        int p;
        cin>>p;
        if(p == 1) {
            int l, r, u;
            cin>>l>>r>>u;
            l--;r--;
            rangeUpdate(l, r, u, 0, n-1, 0);
        }
        else {
            int k;
            cin>>k;
            cout<<rangeMin(k-1, k-1, 0, n-1, 0)<<endl;
        }
    }
}