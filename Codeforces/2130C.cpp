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

vector<int> dsu;
int parent(int x) {
    if(dsu[x] < 0) return x;
    return dsu[x] = parent(dsu[x]);
}

void merge(int a, int b) {
    int x = parent(a), y = parent(b);
    if(x != y) {
        if(dsu[x] < dsu[y]) {
            dsu[x] += dsu[y];
            dsu[y] = x;
        }
        else {
            dsu[y] += dsu[x];
            dsu[x] = y;
        }
    }
}

static bool compare(vector<int> &a, vector<int> &b) {
    if(a[0] != b[0]) return a[0] < b[0];
    else return a[1] > b[1];
}

// vector<vector<int>> mergeI(vector<vector<int>>& a) {
//     sort(a.begin(), a.end());
//     int n = a.size();
//     vector<vector<int>> ans;
//     ans.push_back(a[0]);
//     for(int i = 1; i < n; i++) {
//         int u = ans.back()[0], v = ans.back()[1];
//         int l = a[i][0], r = a[i][1];
//         if(l >= u && l <= v) ans.back()[1] = max(r, v);
//         else ans.push_back(a[i]);
//     }
//     return ans;
// }

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> edges(n);
    for(int i = 0 ; i < n; i++) {
        int u, v;
        cin>>u>>v;
        edges[i] = {u, v, i+1};
    }
    sort(edges.begin(), edges.end(), compare);
    // for(auto& e : edges) {
    //     for(auto it : e) {
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    vector<int> idx;

    dsu = vector<int>(2*n + 1, -1);
    vector<vector<int>> pairs;
    for(auto& e : edges) {
        if(parent(e[0]) != parent(e[1])) {
            merge(e[0], e[1]);
            idx.push_back(e[2]);
            // pairs.push_back({e[0], e[1]});
        }
    }
    sort(idx.begin(), idx.end());
    cout<<(int)idx.size()<<endl;
    for(auto& i : idx) {
        cout<<i<<" ";
    }
    cout<<endl;
}