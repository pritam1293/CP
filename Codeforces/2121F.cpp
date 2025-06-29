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

vector<int> a, tree;
int inf = 1e15;

void buildTree(int low, int high, int pos) {
    if(low == high) {
        tree[pos] = a[low];
        return;
    }
    int mid = (low + high) / 2;
    buildTree(low, mid, 2 * pos + 1); //left child
    buildTree(mid+1, high, 2 * pos + 2); //right child
    //parent is (pos-1)/2
    tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
}

int rangeQuery(int qlow, int qhigh, int low, int high, int pos) {
    //total overlap
    if(low >= qlow && high <= qhigh) {
        return tree[pos];
    }
    //no overlap
    if(qlow > high || low > qhigh) {
        return -inf;
    }
    //partial overlap
    int mid = (low + high) / 2;
    return max(rangeQuery(qlow, qhigh, low, mid, 2 * pos + 1), rangeQuery(qlow, qhigh, mid+1, high, 2 * pos + 2));
}


void solve() {
    int n, s, x;
    cin>>n>>s>>x;
    a = vector<int>(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    tree = vector<int>(4*n);
    buildTree(0, n-1, 0);
    // map<int,int> idx, mp;
    // int cnt = 0;
    // int sum = 0;
    // for(int i=0;i<n;i++) {
    //     sum += a[i];
    //     if(sum == s && rangeQuery(0, i, 0, n-1, 0) == x) cnt += 1ll;
    //     if(mp.find(sum-s) != mp.end() && rangeQuery(idx[sum] , i, 0, n-1, 0) == x) {
    //         cnt += mp[sum-s];
    //     }
    //     mp[sum]++;
    //     if(idx.find(sum) == idx.end()) {
    //         idx[sum] = i+1;
    //     }
    // }
    // cout<<cnt<<endl;
    map<int,vector<int>> mp;
    int cnt = 0, sum = 0;
    for(int i=0;i<n;i++) {
        sum += a[i];
        if(sum == s && rangeQuery(0, i, 0, n-1, 0) == x) cnt += 1ll;
        
        mp[sum].push_back(i);
    }
    cout<<cnt<<endl;
}