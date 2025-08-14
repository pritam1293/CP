#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
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

vector<int> max_tree, min_tree, a;
int inf = 1e9;

void build_max_tree(int low, int high, int pos) {
    if(low == high) {
        max_tree[pos] = a[low];
        return;
    }
    int mid = (low + high) / 2;
    build_max_tree(low, mid, 2 * pos + 1); //left child
    build_max_tree(mid+1, high, 2 * pos + 2); //right child
    //parent is (pos-1)/2
    max_tree[pos] = max(max_tree[2 * pos + 1], max_tree[2 * pos + 2]);
}

int range_max(int qlow, int qhigh, int low, int high, int pos) {
    //total overlap
    if(low >= qlow && high <= qhigh) {
        return max_tree[pos];
    }
    //no overlap
    if(qlow > high || low > qhigh) {
        return -inf;
    }
    //partial overlap
    int mid = (low + high) / 2;
    return max(range_max(qlow, qhigh, low, mid, 2 * pos + 1), range_max(qlow, qhigh, mid+1, high, 2 * pos + 2));
}

void build_min_tree(int low, int high, int pos) {
    if(low == high) {
        min_tree[pos] = a[low];
        return;
    }
    int mid = (low + high) / 2;
    build_min_tree(low, mid, 2 * pos + 1); //left child
    build_min_tree(mid+1, high, 2 * pos + 2); //right child
    //parent is (pos-1)/2
    min_tree[pos] = min(min_tree[2 * pos + 1], min_tree[2 * pos + 2]);
}

int range_min(int qlow, int qhigh, int low, int high, int pos) {
    //total overlap
    if(low >= qlow && high <= qhigh) {
        return min_tree[pos];
    }
    //no overlap
    if(qlow > high || low > qhigh) {
        return inf;
    }
    //partial overlap
    int mid = (low + high) / 2;
    return min(range_min(qlow, qhigh, low, mid, 2 * pos + 1), range_min(qlow, qhigh, mid+1, high, 2 * pos + 2));
}

int search(vector<int> &idx, int l, int r) {
    int low = 0, high = idx.size()-1;
    int ans = l, mid;
    while(low <= high) {
        mid = (low + high) / 2;
        if(idx[mid] < l) low = mid+1;
        else {
            if(idx[mid] <= r) ans = idx[mid];
            high = mid-1;
        }
    }
    return ans;
}

void solve() {
    int n;
    cin>>n;
    a = vector<int>(n);
    map<int,vector<int>> mp;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        mp[a[i]].push_back(i);
    }
    max_tree = vector<int>(4*n);
    min_tree = vector<int>(4*n);
    build_max_tree(0, n-1, 0);
    build_min_tree(0, n-1, 0);
    int q;
    cin>>q;
    while(q--) {
        int l, r;
        cin>>l>>r;
        l--;r--;
        int minm = range_min(l, r, 0, n-1, 0);
        int maxm = range_max(l, r, 0, n-1, 0);
        if(minm == maxm) {
            cout<<"-1 -1"<<endl;
        }
        else {
            int i = search(mp[maxm], l, r);
            int j = search(mp[minm], l, r);
            cout<< i+1 <<" "<< j+1 <<endl;
        }
    }
}