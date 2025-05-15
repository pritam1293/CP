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

bool isGood(vector<int> &arr, int x, int y) {
    sort(arr.begin(), arr.end());
    if(arr[0] <= y) return false;

    vector<bool> vis(x+1, false);
    queue<int> q;
    q.push(x);
    vis[x] = true;

    while(!q.empty()) {
        int num = q.front();
        q.pop();
        if(num == y) return true;

        for(int val : arr) {
            if(val > num) break;
            int rem = num % val;
            if(!vis[rem]) {
                q.push(rem);
                vis[rem] = true;
            }
        }
    }
    return false;
}

void solve() {
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    vector<bool> good(n+1, false);
    int size = 0;
    for(int k=1;k<=n;k++) {
        vector<int> arr(k);
        for(int j=0;j<k;j++) {
            arr[j] = a[j];
        }
        if(isGood(arr, x, y)) {
            size++;
            good[k] = true;
        }
    }
    cout<<size<<endl;
    for(int i=1;i<=n;i++) {
        if(good[i]) {
            cout<<i<<" ";
        }
    }
    if(size != 0) {
        cout<<endl;
    }
}