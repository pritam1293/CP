// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// void solve();
// int32_t main() {
//     ios_base::sync_with_stdio(0); cin.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("../../input.txt", "r", stdin);
//     freopen("../../output.txt", "w", stdout);
// #endif
//     int t=1;
//     while(t--)  solve();
//     cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
// }

// vector<int> a, tree, lazy;
// int inf = 1e9 + 7;

// void updateRange(int ql, int qr, int val, int low, int high, int pos) {
//     if(low > high) return;
//     //lazy propagation at pos, if not processed process now
//     if(lazy[pos] != 0) {
//         tree[pos] += lazy[pos];
//         if(low != high) {
//             lazy[2*pos + 1] += lazy[pos];
//             lazy[2*pos + 2] += lazy[pos];
//         }
//         lazy[pos] = 0;
//     }

//     //no overlap
//     if(ql > high || qr < low) return;

//     //fully overlap
//     if(low >= ql && high <= qr) {
//         tree[pos] += val;
//         if(low != high) {
//             lazy[2*pos + 1] += val;
//             lazy[2*pos + 2] += val;
//         }
//         return;
//     }

//     //partial overlap
//     int mid = (low + high) / 2;
//     updateRange(ql, qr, val, low, mid, 2*pos + 1);
//     updateRange(ql, qr, val, mid + 1, high, 2*pos + 2);
//     tree[pos] = tree[2*pos + 1] + tree[2*pos + 2];
// }

// void buildTree(int low, int high, int pos) {
//     if(low == high) {
//         tree[pos] = a[low];
//         return;
//     }
//     int mid = (low + high) / 2;
//     buildTree(low, mid, 2 * pos + 1); //left child
//     buildTree(mid+1, high, 2 * pos + 2); //right child
//     //parent is (pos-1)/2
//     tree[pos] = tree[2 * pos + 1] + tree[2 * pos + 2];
// }

// int rangeQuery(int qlow, int qhigh, int low, int high, int pos) {
//     if(low > high) return 0;
//     //lazy propagation at pos, if not processed process now
//     if(lazy[pos] != 0) {
//         tree[pos] += lazy[pos];
//         if(low != high) {
//             lazy[2*pos + 1] += lazy[pos];
//             lazy[2*pos + 2] += lazy[pos];
//         }
//         lazy[pos] = 0;
//     }
//     //total overlap
//     if(low >= qlow && high <= qhigh) {
//         return tree[pos];
//     }
//     //no overlap
//     if(qlow > high || low > qhigh) {
//         return 0;
//     }
//     //partial overlap
//     int mid = (low + high) / 2;
//     return rangeQuery(qlow, qhigh, low, mid, 2 * pos + 1) + rangeQuery(qlow, qhigh, mid+1, high, 2 * pos + 2);
// }


// void solve() {
//     int n, q;
//     cin>>n>>q;
//     a = vector<int>(n);
//     tree = vector<int>(4*n);
//     lazy = vector<int>(4*n);
//     for(int i = 0; i < n; i++) {
//         cin>>a[i];
//     }
//     buildTree(0, n-1, 0);
//     while(q--) {
//         int op;
//         cin>>op;
//         if(op == 1) {
//             //update
//             int k, u;
//             cin>>k>>u;
//             updateRange(k-1, k-1, u - a[k-1], 0, n-1, 0);
//             a[k-1] = u;
//         }
//         else {
//             //query
//             int a, b;
//             cin>>a>>b;
//             cout<<rangeQuery(a-1, b-1, 0, n-1, 0)<<endl;
//         }
//     }
// }
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
//BIT - binary indexed tree
vector<int> a, tree;

int getNext(int i) {
    return i + (i & -i);
}

void updateBIT(int val, int i, int n) {
    while(i <= n) {
        tree[i] += val;
        i = getNext(i);
    }
}

void buildTree(int n) {
    for(int i = 1; i <= n; i++) {
        updateBIT(a[i-1], i, n);
    }
}

int getParent(int i) {
    return i - (i & -i);
}

int getSum(int i) {
    int sum = 0;
    while(i > 0) {
        sum += tree[i];
        i = getParent(i);
    }
    return sum;
}

void solve() {
    int n, q;
    cin>>n>>q;
    a = vector<int>(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    tree = vector<int>(n+1);
    buildTree(n);
    while(q--) {
        int p;
        cin>>p;
        if(p == 1) {
            int k, u;
            cin>>k>>u;
            int val = u - a[k-1];
            a[k-1] = u;
            updateBIT(val, k, n);
        }
        else {
            int a, b;
            cin>>a>>b;
            cout<<getSum(b) - getSum(a-1)<<endl;
        }
    }
}