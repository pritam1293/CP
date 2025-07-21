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

vector<int> pre, tree;
int inf = INT_MIN;

void buildTree(int low, int high, int pos) {
    if(low == high) {
        tree[pos] = pre[low];
        return;
    }
    int mid = (low + high) / 2;
    buildTree(low, mid, 2 * pos + 1); //left child
    buildTree(mid+1, high, 2 * pos + 2); //right child
    //parent is (pos-1)/2
    tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
}

int rangeQuery(int qlow, int qhigh, int low, int high, int pos) {
    if(qlow > qhigh) return inf;
    //total overlap3
    if(low >= qlow && high <= qhigh) {
        return tree[pos];
    }
    //no overlap
    if(qlow > high || low > qhigh) {
        return inf;
    }
    //partial overlap
    int mid = (low + high) / 2;
    return max(rangeQuery(qlow, qhigh, low, mid, 2 * pos + 1), rangeQuery(qlow, qhigh, mid+1, high, 2 * pos + 2));
}

bool check(vector<int> &a, int n) {
    pre = vector<int>(n);
    tree = vector<int>(4*n);
    pre[0] = a[0];
    for(int i = 1; i < n; i++) {
        pre[i] = pre[i-1] + a[i];
    }
    buildTree(0, n-1, 0);
    for(int i = 0; i < n; i++) {
        if(pre[i] >= 0) {
            if(rangeQuery(i+1, n-2, 0, n-1, 0) >= pre[i]) return true;
        }
    }
    return false;
}

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        a[i] = a[i] <= k ? 1 : -1;
        // cout<<a[i]<<" ";
    }
    // cout<<endl;
    int l = n, r = -1;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        if(sum >= 0) {
            l = i;
            break;
        }
    }
    sum = 0;
    for(int i = n-1; i >= 0; i--) {
        sum += a[i];
        if(sum >= 0) {
            r = i;
            break;
        }
    }
    if(l < r) {
        cout<<"YES"<<endl;
        return;
    }
    if(check(a, n)) {
        cout<<"YES"<<endl;
        return;
    }
    reverse(a.begin(), a.end());
    if(check(a, n)) {
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}