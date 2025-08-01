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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

vector<long long> max_tree, min_tree, a;
long long inf = 1e9;

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

long long range_max(int qlow, int qhigh, int low, int high, int pos) {
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

long long range_min(int qlow, int qhigh, int low, int high, int pos) {
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

long long maximumProduct(vector<int>& nums, int m) {
    for(auto& num : nums) a.push_back(num);
    int n = a.size();
    long long ans = -1e12;
    max_tree = vector<long long>(4*n);
    min_tree = vector<long long>(4*n);
    build_max_tree(0, n-1, 0);
    build_min_tree(0, n-1, 0);
    for(int i=0;i<n && i+m-1 < n;i++) {
        long long mx1 = range_max(0, i, 0, n-1, 0);
        long long mn1 = range_min(0, i, 0, n-1, 0);
        long long mx2 = range_max(i+m-1, n-1, 0, n-1, 0);
        long long mn2 = range_min(i+m-1, n-1, 0, n-1, 0);
        ans = max(ans, mn1*mn2);
        ans = max(ans, mx1*mx2);
    }
    return ans;
}

void solve() {
    vector<int> nums = {2,-1,2,-6,5,2,-5,7};
    int m = 2;
    cout<<maximumProduct(nums, m)<<endl;
}