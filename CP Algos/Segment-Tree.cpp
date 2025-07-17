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

vector<int> a, tree;
int inf = 98;

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
    buildTree(0, n-1, 0);
    int q;
    cin>>q;
    while(q--) {
        int x, y;
        cin>>x>>y;
        x--;y--;
        cout<<rangeQuery(x, y, 0, n-1, 0)<<endl;
    }
}