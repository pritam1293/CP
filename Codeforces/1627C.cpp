#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}


vector<int> depth;


void check(int node,int parent , vector<int> tree[],map<vector<int>,int> &mp,bool two) {
    if(two) {
        mp[{node,parent}] = 2;
        mp[{parent,node}] = 2;
    }
    else {
        mp[{node,parent}] = 3;
        mp[{parent,node}] = 3;
    }
    // two = !two;

    for(int child : tree[node]) {
        if(child != parent) {
            check(child,node,tree,mp,!two);
        }
    }
}

void dfs(vector<int> tree[], int node, int parent){
    depth[node] = depth[parent] +1;

    for(int child: tree[node]){
        if(child != parent){
            //proceed
            // depth[child] = depth[node]+1;
            dfs(tree, child, node);
        }
    }
}


void solve() {
    int n;
    cin>>n;
    depth = vector<int>(n+1);
    vector<int> tree[n+1];
    vector<vector<int>> edges(n-1, vector<int>(2));
    for(int i=0;i<n-1;i++) {
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        edges[i] = {u,v};
    }

    for(int i=1;i<=n;i++) {
        if(tree[i].size() > 2) {
            cout<<-1<<endl;
            return;
        }
    }

    dfs(tree, 1, 0);

    int node = 0;
    int maxm = 0;

    for(int i=1;i<=n;i++) {
        if(depth[i] > maxm) {
            maxm = depth[i];
            node = i;
        }
    }

    map<vector<int>,int> mp;
    bool two = true;

    check(node,-1,tree,mp,two);

    for(auto v : edges) {
        cout<<mp[v]<<" ";
    }
    cout<<endl;
}
