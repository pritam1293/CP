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
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

vector<int> a, tree, lazy, ft;//ft - frenwick tree or BIT - Binary indexed tree
int inf = 1e9 + 7;

/*
to get next index
    1. 2's complement of get minus of index
    2. AND this with index
    3. Add it to index
*/

int getNextIndex(int i) {
    return i + (i & -i);
}

void updateBIT(int val, int i, int n) {
    while(i <= n) {
        ft[i] += val;
        i = getNextIndex(i);
    }
}

void createTree(int n) {
    ft = vector<int>(n+1);
    for(int i = 1; i <= n; i++) {
        updateBIT(a[i-1], i, n);
    }
}

/*
to get the parent
    1. 2's complement to get minus of index
    2. AND this with index
    3. Subtract that from index
*/

int getParent(int i) {
    return i - (i & -i);
}

int getSum(int i) {//sum in the range [0, i]
    int sum = 0;
    while(i > 0) {
        sum += ft[i];
        i = getParent(i);
    }
    return sum;
}

void updateRange(int ql, int qr, int val, int low, int high, int pos) {
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
    }

    //partial overlap
    int mid = (low + high) / 2;
    updateRange(ql, qr, val, low, mid, 2*pos + 1);
    updateRange(ql, qr, val, mid + 1, high, 2*pos + 2);
    tree[pos] = min(tree[2*pos + 1], tree[2*pos + 2]);
}

void buildTree(int low, int high, int pos) {
    if(low == high) {
        tree[pos] = a[low];
        return;
    }
    int mid = (low + high) / 2;
    buildTree(low, mid, 2 * pos + 1); //left child
    buildTree(mid+1, high, 2 * pos + 2); //right child
    //parent is (pos-1)/2
    tree[pos] = min(tree[2 * pos + 1], tree[2 * pos + 2]);
}

int rangeQuery(int qlow, int qhigh, int low, int high, int pos) {
    //total overlap
    if(low >= qlow && high <= qhigh) {
        return tree[pos];
    }
    //no overlap
    if(qlow > high || low > qhigh) {
        return inf;
    }
    //partial overlap
    int mid = (low + high) / 2;
    return min(rangeQuery(qlow, qhigh, low, mid, 2 * pos + 1), rangeQuery(qlow, qhigh, mid+1, high, 2 * pos + 2));
}

void solve() {
    a = {1, 2, 3, 4, 5, 6, 7};
    int n = a.size();
    tree = vector<int>(4*n);
    lazy = vector<int>(4*n);
    buildTree(0, n-1, 0);

    // int q;
    // cin>>q;
    // while(q--) {
    //     int x, y;
    //     cin>>x>>y;
    //     x--;y--;
    //     cout<<rangeQuery(x, y, 0, n-1, 0)<<endl;
    // }
}